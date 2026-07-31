## SFML Setup (Visual Studio 2022)

### 1. Download SFML

Download **SFML 2.6.2** for **Visual Studio 2022** (32-bit or 64-bit depending on your project configuration).

### 2. Extract the archive

Extract the downloaded SFML archive to a location of your choice, for example:

```text
C:\SFML-2.6.2
```

---

### 3. Configure your Visual Studio project

#### Include Directories

**Project → Properties → C/C++ → General → Additional Include Directories**

```text
$(ProjectDir)\include;
C:\SFML-2.6.2\include;
```

---

#### Library Directories

**Project → Properties → Linker → General → Additional Library Directories**

```text
C:\SFML-2.6.2\lib
```

---

#### Linker Dependencies

**Project → Properties → Linker → Input → Additional Dependencies**

For **Release**:

```text
sfml-graphics.lib
sfml-window.lib
sfml-system.lib
sfml-audio.lib
```

For **Debug**, use the debug libraries instead:

```text
sfml-graphics-d.lib
sfml-window-d.lib
sfml-system-d.lib
sfml-audio-d.lib
```

---

### 4. Copy the required DLL files

Copy the required DLL files from:

```text
SFML\bin
```

to your application's output directory (for example `x64/Debug` or `x64/Release`).

```
SFML/bin
    ↓
Project/x64/Debug/
```

> **Note:** If you are building in **Debug**, copy the `*-d-2.dll` files.  
> If you are building in **Release**, copy the standard `.dll` files.