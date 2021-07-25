# _Base Makefile for 42 project_  
## _Intro_
This is a sample for your 42 projects !
Feel free to modify and re-use this project for your own needs.
I've put a few files just so you can test the Makefile before modifying it.
If you want to check what the ```LDFLAGS``` does, just uncomment the lines in the ```srcs/testleaks.c``` file.

NB: you might want to change the 42 headers in both Makefiles as this is my personnal one.

## _List of commands:_  

* create executable:  
```make```
or
```make all```
or
```make testleaks```

* create bonus executable:  
```make bonus```

* cleanup object files:  
```make clean```

* cleanup object files and binaries:  
```make fclean```

* check norminette 42:  
```make norm```

## _How does it work ?_
This Makefile will compile all of the ```*.c``` specified in the ```SRCS``` variable,
then will do a call to the Makefile in the libft folder to compile your ```libft.a``` library,
and will finish by compiling all your object files with your libft.a library under an executable named after the variable ```NAME``` 
For more information on how Makefile works please consult the man pages.
