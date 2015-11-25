var addon = require('bindings')('addon');

addon.getObjectInCallback(function(obj){
  console.log(JSON.stringify(obj)); // 'hello world'
});