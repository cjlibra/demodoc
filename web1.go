package main
import (
	"fmt"
	"log"
	"net/http"
	//	"strings"
)

func SayHello(w http.ResponseWriter, r *http.Request) {
	r.ParseForm()                   //开始解析参数，默认是不会解析的
	fmt.Println(r.Form)             //把参数信息打印出来
	fmt.Println("path", r.URL.Path) //目录信息打印出来
	fmt.Println("scheme", r.URL.Scheme)
	fmt.Println(r.Form["url_long"])
	for k, v := range r.Form { //迭代参数
		fmt.Println("key:", k)
		fmt.Println("value:", v)
		fmt.Fprintf(w, "key:%s,value:%s", k, v)
	}
	//fmt.Fprintf(w) //把字符串写入客户端
	fmt.Fprint(w, "\r\n")
	fmt.Fprintln(w, "Hello world!")
}

func main() {
	http.HandleFunc("/def", SayHello) //设置访问路由
	http.Handle("/res/", http.FileServer(http.Dir("res/")))
	err := http.ListenAndServe(":9001", nil)
	if err != nil {
		log.Fatal("listen And Server,", err)
	}
}