📘 Address Book Project – Documentation
🧠 Overview

This is a C-based Address Book System that allows users to:

Add new contacts
Search for contacts by name, phone, or email
Edit existing contact details
Delete contacts
Sort and list contacts (by name, phone, or email)
Save all data to a file (Contact.csv)
Load saved data on startup

📂 Project Structure

address-book/
├── main.c                 # Entry point – displays menu and handles user actions
├── contact.c/.h           # Core logic: CRUD operations, search, sort, validations
├── file.c/.h              # Handles file I/O for saving/loading contacts
├── Contact.csv            # Auto-generated CSV file to persist contact data


🚀 Features & Functionality

Feature	Description : 
Add Contact	   -> Prompts for name, phone, and email. Validates and ensures uniqueness.
Search Contact -> Search by name, phone, or email (supports partial matches).
Edit Contact   -> Edit any detail using name/phone/email as identifiers.
Delete Contact -> Remove entries via name, phone, or email.
List Contacts  -> Displays all contacts sorted by chosen field.
Save to File   -> Automatically saves contacts to a CSV file.
Load from File -> Automatically loads saved contacts on startup.

🧪 Validation Logic
Name: Must contain only alphabetic characters and spaces.
Phone: Must be exactly 10 digits and numeric.
Email: Must contain exactly one @ and one ., and follow basic formatting rules.

💾 File Persistence
Uses Contact.csv to store and retrieve contact data.
Each line in the file is a comma-separated entry:
Name,Phone,Email

🛠️ How It Works (Example Menu)

Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice:1

📤 Output Samples

✅ 1. Create Contact 
Enter the name you want to add:123
Invalid name
Enter the name you want to add:pus@123
Invalid name
Enter the name you want to add:pushpa
Enter the phone number you want to add:pushpa
Invalid phone number
Enter the phone number you want to add:123
Invalid phone number
Enter the phone number you want to add:676767676767
Invalid phone number
Enter the phone number you want to add:8888888888
pushpa 8888888888 pushpa@gmail.com
The phone number is already present in addressBook
Enter the phone number you want to add:1919191919
Enter the new_email you want to add:pushpa@gmailcom
Invalid email number
Enter the new_email you want to add:pushpagmail.com@123
Invalid email number
Enter the new_email you want to add:@pushpa.com
Invalid email number
Enter the new_email you want to add:pushpa@.com
Invalid email number
Enter the new_email you want to add:pushpa@gmail.com
pushpa 8888888888 pushpa@gmail.com
The email is already present in addressBook
Enter the new_email you want to add:abc@gmail.com
Contact added successfully.
Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice:2


🔍 2. Search Contact

What you want to search
 1.search by name
 2.search by phone
 3.search by email
Enter your choice: 1
Enter the name you want to search: pushpa123
Invalid name
Enter the name you want to search: push
pushpa 8888888888 pushpa@gmail.com
pushpa 0909009090 abc@gmail.com
you want to search again press Y/N:Y
What you want to search
 1.search by name
 2.search by phone
 3.search by email
Enter your choice: 1
Enter the name you want to search: abc
Entered name is not present in addressbook
you want to search again press Y/N:Y
What you want to search
 1.search by name
 2.search by phone
 3.search by email
Enter your choice: 2
Enter the phone you want to search: 123sgd
Invalid phone number
Enter the phone you want to search: 7778889999
David Brown 7778889999 david@example.com
you want to search again press Y/N:y
What you want to search
 1.search by name
 2.search by phone
 3.search by email
Enter your choice: 3
Enter the email you want to search: abc.com@
Invalid email number
Enter the email you want to search: abc@gmail.c
pushpa 0909009090 abc@gmail.com
you want to search again press Y/N:N
Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice:3


📝 3. Edit Contact

What you want to edit
 1.edit by name
 2.edit by phone
 3.edit by email
Enter your choice: 1
Enter the name you want to edit: 12ghk
Invalid name
Enter the name you want to edit: pushpa
13
pushpa 8888888888 pushpa@gmail.com
pushpa 0909009090 abc@gmail.com
Printed details Successfully
Enter the phone number you want to edit name:8888888888
Enter the new name: vidya
Edited the name successfully
you want to continue again press Y/N:y
What you want to edit
 1.edit by name
 2.edit by phone
 3.edit by email
Enter your choice: 2         
Enter the phone you want to edit: 12nmf
Invalid phone number
Enter the phone you want to edit: 0909009090
pushpa 0909009090 abc@gmail.com
Printed details Successfully
Enter the new phone number: 1212121212
Edited the phone successfully
What you want to edit
 1.edit by name
 2.edit by phone
 3.edit by email
Enter your choice: 3
Enter the email you want to edit: abc
Invalid email number
Enter the email you want to edit: abc@gmail.com
pushpa 1212121212 abc@gmail.com
Printed details Successfully
Enter the new email: cba@gmail.com
Edited the email successfully
you want to continue again press Y/N:Y
What you want to edit
 1.edit by name
 2.edit by phone
 3.edit by email
Enter your choice: 1
Enter the name you want to edit: asha
Entered name not present in addressBook
you want to continue again press Y/N:Y
What you want to edit
 1.edit by name
 2.edit by phone
 3.edit by email
Enter your choice: 2
Enter the phone you want to edit: 1010100101
Entered phone number not present in addressBook
you want to continue again press Y/N:Y
What you want to edit
 1.edit by name
 2.edit by phone
 3.edit by email
Enter your choice: 3
Enter the email you want to edit: mnop@gmail.com
Entered email not present in addressBook
you want to continue again press Y/N:N
Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 4


❌ 4. Delete Contact
Do you want to delete press Y/N:Y
What you want to delete
 1.delete by name
 2.delete by phone
 3.delete by email
Enter your choice: 1
Enter the name you want to delete: hjk
Entered name not present in addressBook
you want to continue again press Y/N:Y
What you want to delete
 1.delete by name
 2.delete by phone
 3.delete by email
Enter your choice: 1
Enter the name you want to delete: gyt123
Invalid name
you want to continue again press Y/N:Y
What you want to delete
 1.delete by name
 2.delete by phone
 3.delete by email
Enter your choice: 1
Enter the name you want to delete: vidya
vidya 9999999999 vidya@gmail.com
vidya 5555555555 xyz@gmail.com
Printed details Successfully
Enter the phone you want to delete name: 5555555555
deleted the name successfully
you want to continue again press Y/N:Y
What you want to delete
 1.delete by name
 2.delete by phone
 3.delete by email
Enter your choice: 2
Enter the phone number you want to delete: 999as
Invalid phone number
Enter the phone number you want to delete: 9696969687
Entered phone not present in addressBook
you want to continue again press Y/N:Y
What you want to delete
 1.delete by name
 2.delete by phone
 3.delete by email
Enter your choice: 2
Enter the phone number you want to delete: 9999999999
vidya 9999999999 vidya@gmail.com
Printed details Successfully
deleted the phone number successfully
you want to continue again press Y/N:Y
What you want to delete
 1.delete by name
 2.delete by phone
 3.delete by email
Enter your choice: 3
Enter the email you want to delete: klm@mnocom.
Invalid email number
Enter the email you want to delete: lmg@gmail.com
Entered email not present in addressBook
What you want to delete
 1.delete by name
 2.delete by phone
 3.delete by email
Enter your choice: 3
Enter the email you want to delete: john@example.com
John Doe 1234567890 john@example.com
Printed details Successfully
deleted the email successfully
Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 5


📜 5. List All Contacts (Sorted by Name)
Select sort criteria:
1. Sort by name
2. Sort by phone
3. Sort by email
Enter your choice: 1
Name       Phone number   email Id

Alice Smith 0987654321 alice@example.com
Bob Johnson 1112223333 bob@company.com
Carol White 4445556666 carol@company.com
David Brown 7778889999 david@example.com
Eve Davis 6665554444 eve@example.com
Frank Miller 3334445555 frank@example.com
Grace Wilson 2223334444 grace@example.com
Hannah Clark 5556667777 hannah@example.com
Ian Lewis 8889990000 ian@example.com
pushpa 8888888888 pushpa@gmail.com
pushpa 0909009090 abc@gmail.com
vidya 5555555555 xyz@gmail.com
Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 5
Select sort criteria:
1. Sort by name
2. Sort by phone
3. Sort by email
Enter your choice: 2
Name       Phone number   email Id

pushpa 0909009090 abc@gmail.com
Alice Smith 0987654321 alice@example.com
Bob Johnson 1112223333 bob@company.com
Grace Wilson 2223334444 grace@example.com
Frank Miller 3334445555 frank@example.com
Carol White 4445556666 carol@company.com
vidya 5555555555 xyz@gmail.com
Hannah Clark 5556667777 hannah@example.com
Eve Davis 6665554444 eve@example.com
David Brown 7778889999 david@example.com
pushpa 8888888888 pushpa@gmail.com
Ian Lewis 8889990000 ian@example.com
Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 5
Select sort criteria:
1. Sort by name
2. Sort by phone
3. Sort by email
Enter your choice: 3
Name       Phone number   email Id
pushpa 0909009090 abc@gmail.com
Alice Smith 0987654321 alice@example.com
Bob Johnson 1112223333 bob@company.com
Carol White 4445556666 carol@company.com
David Brown 7778889999 david@example.com
Eve Davis 6665554444 eve@example.com
Frank Miller 3334445555 frank@example.com
Grace Wilson 2223334444 grace@example.com
Hannah Clark 5556667777 hannah@example.com
Ian Lewis 8889990000 ian@example.com
pushpa 8888888888 pushpa@gmail.com
vidya 5555555555 xyz@gmail.com
Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
Enter your choice: 6


💾 6. Exit
Saving and Exiting...
Contacts successfully saved to Contact.csv


🧾 Project Summary
This Address Book System is a comprehensive C-based console application designed to manage personal or professional contact information efficiently. It features essential functionalities such as adding, searching, editing, deleting, and listing contacts with sorting capabilities. It supports data persistence through file operations, ensuring that contacts are saved and loaded automatically across sessions. With robust input validation and a set of preloaded dummy contacts, the system is ideal for both practical use and demonstration purposes. The modular code structure ensures clarity, maintainability, and ease of future enhancements.