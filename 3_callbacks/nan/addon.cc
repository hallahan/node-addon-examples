#include <nan.h>

NAN_METHOD(getObjectInCallback) {
  
  // Create Object
  std::string str = "This is a std::string in C++.";
  long myLong = 34343434;
  double myDouble = -128.23245;
  bool myBool = true;

  v8::Local<v8::Object> obj = Nan::New<v8::Object>();
  obj->Set(Nan::New("msg").ToLocalChecked(), Nan::New(str).ToLocalChecked());
  obj->Set(Nan::New("myLong").ToLocalChecked(), Nan::New<v8::Number>(myLong));
  obj->Set(Nan::New("myDouble").ToLocalChecked(), Nan::New<v8::Number>(myDouble));
  obj->Set(Nan::New("myBool").ToLocalChecked(), Nan::New<v8::Boolean>(myBool));

  v8::Local<v8::Function> cb = info[0].As<v8::Function>();
  const unsigned argc = 1;
  v8::Local<v8::Value> argv[argc] = { obj };
  Nan::MakeCallback(Nan::GetCurrentContext()->Global(), cb, argc, argv);
}

NAN_MODULE_INIT(Init) {
  NAN_EXPORT(target, getObjectInCallback);
}

NODE_MODULE(addon, Init)
