var addon = require('bindings')('addon');

addon(function(obj){
  console.log(JSON.stringify(obj)); // 'hello world'
});