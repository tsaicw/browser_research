#include<iostream>
#include<v8.h>

using namespace std;
using namespace v8;

// This function returns a new array with three elements, x, y and z.
Handle<Array> NewPointArray(int x, int y, int z){
    // We will be creating temporary handles so we use a handle scope.
    HandleScope handle_scope;

    // Create a new empty array.
    Local<Array> array = Array::New(3);

    // Return an empty result if there was an error creating the array
    if(array.IsEmpty()) return Handle<Array>();

    // Full out the values.
    array->Set(0, Integer::New(x));
    array->Set(1, Integer::New(y));
    array->Set(2, Integer::New(z));

    // Return the value through Close.
    return handle_scope.Close(array);
}



int main(int argc, char* argv[]){
    // The outer handle scope.
    HandleScope handle_scope;

    Persistent<Context> context = Context::New();
    Context::Scope context_scope(context);

    // Used to hold the returned array.
    Handle<Array> array = NewPointArray(10, 20, 30);

    Local<Value> x = array->Get(0);
    Local<Value> y = array->Get(1);
    Local<Value> z = array->Get(2);

    // Print the array's value.
    cout<<"x = "<<Integer::Cast(*x)->Value()<<endl;
    cout<<"y = "<<Integer::Cast(*y)->Value()<<endl;
    cout<<"z = "<<Integer::Cast(*z)->Value()<<endl;

    context.Dispose();

    return 0;
}

