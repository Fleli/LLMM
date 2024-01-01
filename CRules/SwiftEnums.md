# Swift Enums

I've written a lot of Swift and have fallen in love with enums + associated values, e.g.
```swift
enum App {
    case compass
    case facebook(friends: Int, name: String)
    case phone(contacts: [String]) 
}
```

Each case has zero or more _associated values_. If a variable `a: App` takes the `.facebook` case, it has an associated `Int` and a value `String`. If the case is `.phone`, it has an array of `String` as its associated value.

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
- The associated value is declared as `void *`. If the case is `.compass` (which has no associated value), the `associated_value` is set to `NULL`. For the case `.facebook`, we point to a struct holding an `int` (friends) and `char *` (name). For the `.phone` case, the associated value points to a `char **` (or similar) that represents the array of strings.
- The struct's destructor checks which case is chosen, and destroys itself appropriately.
