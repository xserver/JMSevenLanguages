var http = require('http');
var url = require('url');
var fs = require("fs"); // file system
var path = require("path"); // 路径解析模块

const ip = '127.0.0.1';
const port = 8081;

http.createServer( function(request, response) {

    console.log("url = " + request.url);
    var pathname = url.parse(request.url).pathname;

    if (pathname === '/') {
        console.log("pathname = / , change to index.html");
        pathname = '/index.html';
    }
    console.log("pathname = " + pathname);

    //  动态呢 ？
    //  静态文件读取
    fs.readFile(pathname.substr(1), function(err, data) {

        if (err) {
            console.log(err);
            response.writeHead(404, { 'Content-Type': 'text/html;charset=utf-8' });
            response.write('HTTP 状态码: 404 : NOT FOUND');
        } else {

            response.writeHead(200, { 'Content-Type': 'text/html;charset=utf-8' });
            response.write(data.toString());
        }
        
        response.end(); //  发送响应数据
    });

}).listen(port);

// 控制台会输出以下信息
console.log('Server running at http://127.0.0.1:8081/');