// 使用 window.alert() 弹出警告框。
// 使用 document.write() 方法将内容写到 HTML 文档中。
// 使用 innerHTML 写入到 HTML 元素。
// 使用 console.log() 写入到浏览器的控制台。

console.log("hello world!");

function string2int(s) {
    let ay = s.split('');

    var s1 = ay.map(function(x) {
        return x - 0;
    });



    return s1.reduce(function(x, y) {
        console.log(y);
        y = x * 10 + y;
        console.log(y);
        return y;
    });

}
string2int('12345');


