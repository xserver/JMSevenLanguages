function func1() {
	var num = 1;

	function func2() {
		return num + 1;
	}
	return func2;
}

var num = func1()();

console.log(num);