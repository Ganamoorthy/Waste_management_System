# Waste management System

# Smart Waste Bin Management System (C Project)

### Overview
This is an interactive C-based project simulating a **Smart Waste Bin Management System** designed for a university environment.  
It allows users (students, staff, and administrators) to:
- Check if bins are full
- Manage bin data
- Submit complaints or feedback
- Handle user account registration and login (with basic encryption)

This project demonstrates skills in **file handling**, **loops**, **conditional logic**, **menu-driven programming**, and **user data encryption** in C.

---

### Features

#### 1. Bin Management
- Add or delete bin numbers from `bin.txt`
- Check if a bin is full or not
- Automatically log full bins in `bin_info.txt`

#### 2. Complaint & Feedback System
- Users can submit complaints and feedback
- All submissions are recorded in `comp_data.txt`
- Includes user details: name, student number, department, and message

#### 3. Admin Features
- Register and log in as an administrator
- Encrypted username and password stored in `cred.txt`
- Access admin panel to manage bins or view complaints

#### 4. User Authentication
- Basic username and password encryption (custom algorithm)
- Prevents duplicate usernames
- Supports login verification via encrypted credentials

---

### File Structure

| File | Purpose |
|------|----------|
| `main.c` | Main program source code |
| `bin.txt` | Stores all bin numbers |
| `bin_info.txt` | Logs bins marked as full |
| `cred.txt` | Keeps encrypted username-password pairs |
| `comp_data.txt` | Stores complaints and feedback |
| `temp.txt` | Temporary file for bin deletion |

---

### How to Compile & Run

1. **Compile the code**

       gcc main.c -o bin_system

2. **Run the program**
   
        ./bin_system


3. **Follow on-screen instructions**

- You will be asked to identify as Student, Academic, or Non-Academic.
- Then you can:
  - Manage bins (Bin option)
  - Submit complaints (Complain option)
  - Log in or register as admin (Admin option)

---

### Admin Workflow

1. Choose **Admin** from the main menu.
2. Options include:
- `1. User Registration`
- `2. User Login`
- `3. Return to Main Menu`
3. After successful login, choose among:
- Check Bin Status
- Add/Delete Bins
- View Complaints/Feedbacks

---

### Example Files

- **bin.txt**

101
102
103
104


- **cred.txt**
  
encryptedUser1 encryptedPassword1

encryptedUser2 encryptedPassword2


---

### Key Functions

| Function | Description |
|-----------|-------------|
| `user_enc()` | Encrypts username using a cubic formula |
| `pass_enc()` | Encrypts password using a quadratic formula |
| `cred_save()` | Saves credentials to file |
| `username_check()` | Verifies if username exists |
| `user_check()` | Verifies username and password pair |
| `binchkandsend()` | Checks if a bin is full and logs it |
| `addBin()` / `deleteBin()` | Manage bin numbers dynamically |
| `comp_fed()` | Displays complaints and feedback |

---

### Future Improvements

- Implement encrypted file storage with reversible decryption.
- Introduce timestamp logging for complaints and feedback.
- Improve data validation and prevent direct text file tampering.
- Create a front-end interface using C++ or Python integration.

---

### Contributors

- **Project Team:**
  
Dilukshan Subramaniyam

Hashmithan Sugumar

Siboshan Anthonipplai

Ganamoorthy Sivadhas 

- **Language Used:** C
- **Environment:** GCC / Code::Blocks / Visual Studio Code

---

### License
This project is released for educational use under the MIT License.

