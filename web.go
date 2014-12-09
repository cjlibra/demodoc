package main

import (
        "flag"
        "io/ioutil"
        "log"
        "net/http"
        "os"
        "strings"
		"fmt"
)

var realPath *string

 
func staticResource(w http.ResponseWriter, r *http.Request) {
        r.ParseForm()  
		if len(r.Form["file"]) >0  {
			fmt.Println(r.Form["file"])
			fmt.Println(r.Form["act"])
			str := r.Form["file"][0]+ "  " + r.Form["act"][0]
			
			myfin ,err := os.Create( "set.set")
			defer myfin.Close()
			if err != nil {
				  //  log.Fatal("static resource:", err)
				  w.Write([]byte("error open set.set"))
			} 
			myfin.WriteString(str)
		}
        path := r.URL.Path
        request_type := path[strings.LastIndex(path, "."):]
        switch request_type {
        case ".css":
                w.Header().Set("content-type", "text/css")
        case ".js":
                w.Header().Set("content-type", "text/javascript")
        default:
        } 
        fin, err := os.Open(*realPath + path)
        defer fin.Close()
        if err != nil {
              //  log.Fatal("static resource:", err)
        } 
        fd, _ := ioutil.ReadAll(fin)
        w.Write(fd)
}

func main() {
        realPath = flag.String("path", "", "static resource path")
        flag.Parse()
		
		*realPath = "res/biaogweb"

        http.HandleFunc("/", staticResource)
		 
        err := http.ListenAndServe(":9001", nil)
        if err != nil {
                log.Fatal("ListenAndServe:", err)
        } 
}

