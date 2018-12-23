// ajax.js

var request = new XMLHttpRequest();
if (request) {
	console.log('YES');

} else {

}


if (window.XMLHttpRequest) {
	console.log('YES');
	

} else {
	console.log('NO');
}

$.ajax({
	type:"GET",
	url:"...",
	dataType:"json",
	data:{name:$("#username").val()},
	success:function(data) {data.success},
	error:function(jqXHR) {},
})