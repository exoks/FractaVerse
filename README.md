### **FractaVerse** ###

`FractaVerse` is an advanced C-based fractal visualization project that brings mathematical beauty to life using the 42MLX graphics library. It makes exploring mathematical graphics both fun and interactive.

- Built on my **`libft`** and **`ft_printf`** projects for optimized formatted output
- Includes **two usage menus**:
  - A **CLI usage menu** displayed in the terminal when running the program. 
  - An **interactive in-program menu** that guides users on how to navigate and use features. 
- Renders the **Mandelbrot** set, **Julia** set, and **Burning Ship** fractals.
- Supports **zooming in and out** for detailed exploration.
- Includes **automatic color shifting** for dynamic visual effects.

### **Available Fractals** ###
<table>
  <tr>
    <td><img width="715" alt="Image" src="https://github.com/user-attachments/assets/4c25557f-0fca-4cee-98c8-c77085853ead" /></td>
    <td><img width="715" alt="Image" src="https://github.com/user-attachments/assets/04c823f9-9248-4ee3-aa1e-274156c6395b" /></td>
    <td><img width="715" alt="Image" src="https://github.com/user-attachments/assets/56241d43-804f-4013-bd4a-1cd7e487d147" /></td>
  </tr>
</table>

### **Getting Started** : ###

#### **Prerequisites** ####
Before running `FractaVerse`, ensure you have the following:

- **`MacOS`** Operating system 
- The [**42-MiniLibx**](https://harm-smits.github.io/42docs/libs/minilibx) graphics library installed
- A `C` compiler (**`gcc`** or **`clang`**)
- **GNUMake** installed

#### **Installation** ####
1. Clone the repository
```sh
git clone https://github.com/exoks/FractaVerse.git
cd FractaVerse
```

2. Compile the project:
```sh
make
```
  * This will generate the `fractol` executable.

```sh
make bonus
```
- This will generate the `fractol_bonus` executable.

#### **Running the Program:** ####
```sh
./fractol
```
* Or 
```sh
./fractol_bonus
```
***Running the program will display a CLI Usage Menu :***

<table>
  <tr>
    <th><code>fractol</code> Usage Menu</th>
    <th><code>fractol_bonus</code> Usage Menu</th>
  </tr>
  <tr>
    <td><img width="684" alt="Image" src="https://github.com/user-attachments/assets/c801bc86-d597-4cd8-9ddf-0affbd5a06e5" /></td>
    <td><img width="735" alt="Image" src="https://github.com/user-attachments/assets/f08486f8-1c13-4d2b-8140-c1ce6d073444" /></td>
  </tr>
</table>

**Enjoy the Fractal Universe.**

### **Cleanup :** ###
* To remove Object files, run:
```sh
make clean
```

* To remove all binaries and object files, run:
```sh
make fclean
```

---
