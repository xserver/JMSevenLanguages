package main

import (
	"fmt"
	"os/exec"
	"os"
	"bufio"
	"io"
	"bytes"
	"log"
	"strings"
    "time"
)

var cwCmd *exec.Cmd

//  http://blog.csdn.net/qq_36874881/article/details/78234005
func main() {
	// execCommandA()
	err := execCommandB()
    fmt.Println(err)
}

func execCommandA() {
	cmd := exec.Command("tr", "a-z", "A-Z")
	cmd.Stdin = strings.NewReader("some input")
	var out bytes.Buffer
	cmd.Stdout = &out
	err := cmd.Run()
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("in all caps: %q\n", out.String())
}

func stopCommand() {
    if cwCmd != nil && cwCmd.Process.Pid != 0 {
        fmt.Println("** kill pid = ", cwCmd.Process.Pid)
        cwCmd.Process.Kill()
        cwCmd.Process.Release()        
    }
}

//	行读取返回
func execCommandB() error {
	
    projectPath := "/Users/macro/Work/Bond/jiazhangtong/community_iOS_trunk/BondCommunity"
    err := os.Chdir(projectPath)
    if err != nil {
        return err
    }
    
    // cmdstr := "/Users/macro/.fastlane/bin/fastlane beta"
    cmd := exec.Command("/Users/macro/.fastlane/bin/fastlane", "beta")// "sh", "-c"
    cwCmd = cmd

    // fmt.Println(os.Getenv("PATH"))
    // env := os.Environ()
    // env = append(env, fmt.Sprintf("PATH=%s", "$HOME/.fastlane/bin:$PATH"))
    // fmt.Println(os.Getenv("PATH"))
    // cmd.Env = env

    stdout, err := cmd.StdoutPipe()
    if err != nil {
        return err
    }

    cmd.Start() // 后面 cmd.Wait 会一直阻塞等待
    fmt.Println("** pid = ", cmd.Process.Pid)

    time.AfterFunc(10*time.Second, func () {
        stopCommand()
    })

    reader := bufio.NewReader(stdout)
    for {   // 行读取
        line, err := reader.ReadString('\n')
        if err != nil || io.EOF == err {
            break
        }
        fmt.Print(line)
    }

    cmd.Wait()
    return nil
}

// 获取日志句柄
func fastlaneLog() {
    func Open(name string) (*File, error)
}
// 写入
func inputFastlaneLog(text string) {

}
// 关闭
