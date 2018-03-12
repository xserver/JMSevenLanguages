package main

import "github.com/go-martini/martini"

import (
    "fmt"
    "log"
    "os/exec"
	"bytes"
    // "sync"
    // "strings"
)

func main() {
  m := martini.Classic()
  m.Get("/", func() string {
    return "/"
  })

  m.Get("/haha", func() string {
    return "haha"
  })

  m.Get("/build", func() string {
  	res, err := exec_shell("ls .")
	if err != nil {
		return "error"
	}
  	return res
    // return "haha"
  })

  // m.NotFound(func() string {
  //   return "NotFound"
  // })


  m.Run()
}

//阻塞式的执行外部shell命令的函数,等待执行完毕并返回标准输出
func exec_shell(s string) (string, error){

	fmt.Println(s)

	// s := "echo hello world"
	cmd := exec.Command("sh", "-c", s) // "/bin/bash" VS "sh"

	var out bytes.Buffer 
	cmd.Stdout = &out	//指定 out

	err := cmd.Run() // 阻塞直到完成
	if err != nil {
		log.Fatal(err)
	}

	fmt.Printf("out: %q\n", out.String())
	return out.String(), err
}

/*
当一个处理器返回结果的时候, 
Martini 将会把返回值作为字符串写入到当前的http.ResponseWriter
m.Get("/", func() string {
    return "<h1>Hello world!<h1>"
  })


m.Get("/", func() (int, string) {
  return 418, "i'm a teapot" // HTTP 418 : "i'm a teapot"
})

m.Get("/", func(res http.ResponseWriter, req *http.Request) { // res 和 req 是通过Martini注入的
  res.WriteHeader(200) // HTTP 200
})

m.Get("/hello/:name", func(params martini.Params) string {
  return "Hello " + params["name"]
})

m.Get("/hello/**", func(params martini.Params) string {
  return "Hello " + params["_1"]
})


Get    显示 show
Patch  更新 update
Post   创建 create
Put    替换 replace
Delete 删除 destroy
Options  http 选项
NotFound 处理 404


*/