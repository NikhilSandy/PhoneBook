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
1. **Insert/create contact**:
     - A new contact to be inserted in the database. Make sure that              thereis norestriction for the contact with same name.
     - i/p: all the field related to insertion on a new contact
     - o/p: A message showing that contact is created
2. **Edit**:
     - Edit option should be provided to modify the details.
     - i/p: all the fields that can be modified
     - o/p: message showing that contact in modified
3. **Delete:**
     - contact can be deleted as a whole
     - i/p: field to search for contact that is to be deleted
     - o/p: message showing contact is deleted
4. **Search:**
     - provide searching contact via name, mobile number and any other if        you like
     - i/p: provide options to search using name and mobile no.
     - o/p: contact searched
5. **Sort:**
     - Sorting in ascending /descending, professional/personal
     - i/p: Given the database implemented using trees, provide the              options fordisplaying after sorting in a particular manner i.e.          using switch cases likeascending, descending.
     - o/p: sorted list according to the choice of user
6. **Display all:**
     - Display personal list: only personal contacts to be displayed
     - Display professional list: only professional contacts to be              displayed
     - i/p: option asking to show contacts
     - o/p: list as per option selected

7. **Range Search:** 
     - Given two mobile numbers, From-Mobile-Number and To-Mobile-Number,        display the set of records having mobile number (as integer)              between therange of From-Mobile-Numbe upto To-Mobile-Number (both        inclusive)

8. Sort the records in the phone database (i.e. tree) based on first-name. If first-name is
same for multiple people, then the records to be sorted based on mobile number.
