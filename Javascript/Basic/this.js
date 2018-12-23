
// this 有坑：

// var a = 10;
// function test(){
//     a = 100;
//     console.log('1 = ' + a);
//     console.log('2 = ' + this.a);
//     var a;
//     console.log('3 = ' + a);
// }

// test1();


// var b = 100;
// function test2(){
//     console.log(b);
//     var b = 10;
//     console.log(b);
// }
// test2();

var c = 100;
function test3(){
    console.log(c);
    c = 10;
    console.log(c);
}
test3();
console.log(c);