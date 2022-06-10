# goldfish
The goldfish programming language

# Compiler description
This is a short description of an enhanced C language. The output is pure ANSI C. There is one compile module that imports everything that is needed to compile the program. (like GO does) As much as possible, the input is C and is simply passed through to the output. All operations are performed in a single pass. The normal C preprocessor is used at the source level to do things like includes.

* Adding name spaces. All symbols are decorated with their name space, with the goal of allowing the same names to be defined in different modules with no name collisions. A name space simply unconditionally edits the name.

* Add classes and objects. The "self" or the "this" pointer is hidden in class method parameters and used according to needs must. A class defines a structure. 

* Adding function overloading according to return type and parameter types. The name is simply decorated to include these into the name. 

* Exceptions. Exceptions are implemented using the setjmp/longjmp library.

* Garbage collection using a regular GC library. Override the memory allocation routines as needed to hide it from the outside.

* Imports. When a modules is compiled to C, a header is created that can be included to do an "import" of the module. The import key word is used as a source keyword. The link phase is edited to look for an imported module.


# The plan
This is the implementation plan.

* Translate a very limited subset of C. This is mostly a pass-through where almost no actual translation is done, but the infrastructure for creating files, etc is in place. Mindful of the input and the output. These features refer to the input.

	* File access.

	* Search paths for source files and libraries.

	* Command line parsing.

	* The general driver that connects the C compiler parts together.

* Add the features, one by one, starting with the least impactful and
building on that.

	* Add garbage collection.

	* Translate name spaces.

	* Overload function names.

	* Add classes.

	* Add exceptions.
