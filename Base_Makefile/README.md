# Base Makefile

### **Suivie du projet : *Base Makefile***
- [x] Basic 42 rules
- [x] Norminette and Debug rules

### **List of commands :**  

* create Mandatory part:  
```make```

* create Bonus part:  
```make bonus```

* Recompile Mandatory part:  
```make re```

* Clean object files:  
```make clean```

* Clean executables and objects files:  
```make fclean```

* launch in debug mode:  
```make debug```

* check 42 norm:  
```make norm```

### **Git architecture :**
```
└── master
    └── main
```

### **Project architecture :**
```
├── Makefile
|
├── header
|   ├── test.h
|   └── test_bonus.h
|
├── srcs
|   └── main.c
|
├── srcs_mac
|   └── display_arg_mac.c
|
├── srcs_linux
|   └── display_arg_linux.c
|
├── srcs_bonus
|   └── main_bonus.c
|
└── libft
   	└──── Makefile
	   |
	   ├── header
	   |	└── libft.h
	   └── srcs
      		└── ft_crash.c
```
