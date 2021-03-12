# qbook
Application for booking seats in office

# Dependencies
- Windows and Linux both acceptable
- Qt 5.15.2+
- GCC 10.2.0+

# How to run
Simply proceed with the Qt Creator:
File->New File or Project->Import Project->Git clone->Repository: https://github.com/zRrrGet/qbook.git

Or you can build it manually with qmake

# Usage
In order to login into application you have to create users.ini near executable with following format(spaces are not allowed):
```
login=password
```
Then application will procceed to the next frame with the calendar, where you can choose the dates, and with the lower part of program, where you can see available/occupied seats. You can book a seat for particular time period by clicking on it.
For every booking record there will be a line in bookings.ini with following format:
```
login seat_number(0-39) date(DD:MM:YYYY) start_time(HH:MM) end_time(HH:MM)
```
