# PhoneBook
A phonebook is implemented as an AVL-tree where each
node represent first name,last name and mobile number and you may also add addition
nodes like e-mail, office no., address, etc for every contacts.Personal contact
(name, mobile number, email, type) and Professional contact list (name, mobile number,
email, office number, address,institute/office, type). Mobile number (considered as integer)
can be considered as key of the record.
A field is provided according to which personal and professional contacts are
separated. (Type: personal/professional). In addition, such a phonebook should keep track of
number of phone calls made to different contacts, the date and the duration of the calls.

The following functions/operations are implemented:
1. Insert/create contact:
a. A new contact to be inserted in the database. Make sure that there is no
restriction for the contact with same name.
b. i/p: all the field related to insertion on a new contact
c. o/p: A message showing that contact is created
2. Edit:
a. Edit option should be provided to modify the details.
b. i/p: all the fields that can be modified
c. o/p: message showing that contact in modified
3. Delete:
a. contact can be deleted as a whole
b. i/p: field to search for contact that is to be deleted
c. o/p: message showing contact is deleted
4. Search:
a. provide searching contact via name, mobile number and any other if you like
b. i/p: provide options to search using name and mobile no.
c. o/p: contact searched
5. Sort:
a. Sorting in ascending /descending, professional/personal
b. i/p: Given the database implemented using trees, provide the options for
displaying after sorting in a particular manner i.e. using switch cases like
ascending, descending.
c. o/p: sorted list according to the choice of user
6. Display all:
a. Display personal list: only personal contacts to be displayed
b. Display professional list: only professional contacts to be displayed
c. i/p: option asking to show contacts
d. o/p: list as per option selected

7. Range Search – Given two mobile numbers, From-Mobile-Number and To-Mobile-
Number, display the set of records having mobile number (as integer) between the

range of From-Mobile-Numbe upto To-Mobile-Number (both inclusive)
8. Sort the records in the phone database (i.e. tree) based on first-name. If first-name is
same for multiple people, then the records to be sorted based on mobile number.
