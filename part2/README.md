For part 2 we decided to create the interface for Array for the Object and String classes. Even though String extends the Object class we decided to have a ObjectArray and a StringArray that are independent of each other but still extend from the Object class. We will decrease duplicated code by having StringArray use ObjectArray underneath the hood.

We decided to keep StringArray its own separate class so that it allows the user to build a StringArray without worrying or type checking if each element is a string or another object. Furthermore it will prevent users to put non string objects inside the string array, maintaining uniform data type in the array.

Testing for these interfaces was structured similarly to part1 where the test classes were split up by file.