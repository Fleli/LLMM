# Swift Enums

I've written a lot of Swift and have fallen in love with enums + associated values, e.g.
```swift
enum App {
    case compass
    case facebook(friends: Int)
    case phone(contacts: [String]) 
}
```

Each case has zero or more _associated values_. If a variable `a: App` takes the `.facebook` case, it has an associated `Int` that we can use. If the case is `.phone`, it has an array of `String` as its associated value.

Since I like to use this pattern, I've developed the following solution for C programs:
- We define a struct for the enum with properties for the case and the associated value, e.g.
    ```c
    
    typedef int AppCase;
    
    #define app_case_compass 1
    #define app_case_facebook 2
    #define app_case_phone 3
    
    typedef struct {
        
        AppCase appCase;
        void *associated_value;
        
    } App;
    
    ```
- The associated value