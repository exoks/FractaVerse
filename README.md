### **Fract-ol** ###
`Fract-ol` is an advanced C-based fractal visualization project that brings mathematical beauty to life using the 42MLX graphics library. It makes exploring mathematical graphics both fun and interactive.

- Built on my **libft** and **ft_printf** projects for optimized formatted output
- Includes **two usage menus**:
  - A **CLI usage menu** displayed in the terminal when running the program. 
  - An **interactive in-program menu** that guides users on how to navigate and use features. 
- Renders the **Mandelbrot** set, **Julia** set, and **Burning Ship** fractals.
- Supports **zooming in and out** for detailed exploration.
- Includes **automatic color shifting** for dynamic visual effects.

### **Available Fractals** ###
<table>
  <tr>
    <th>Mandelbrot</th>
    <th>Julia</th>
    <th>Burning ship</th>
  </tr>
  <tr>
    <td><img src="path/to/mandelbrot.png" width="600"></td>
    <td><img src="path/to/julia.png" width="600"></td>
    <td><img src="path/to/burning_ship.png" width="600"></td>
  </tr>
</table>

### **Getting Started** : ###

#### **Prerequisites** ####
Before running `Fract-ol`, ensure you have the following:

- **MacOS** Operating system 
- The [**42-MiniLibx**](https://harm-smits.github.io/42docs/libs/minilibx) graphics library installed
- A C compiler (**gcc** or **clang**)
- **GNUMake** installed

#### **Installation** ####
1. Clone the repository
```sh
git clone https://github.com/exoks/Fract-ol.git
cd fract-ol
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
    <td><img src="path/to/mandelbrot.png" width="700"></td>
    <td><img src="path/to/julia.png" width="700"></td>
  </tr>
</table>

**Enjoy the fractal experience**
# include a gif image for one fractal
---

#### **Cleanup** ####
* To remove Object files, run:
```sh
make clean
```

* To remove all binaries and object files, run:
```sh
make fclean
```

---
