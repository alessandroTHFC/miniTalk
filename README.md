# miniTalk
The purpose of this project is to code a small data exchange program using UNIX signals. It is an introductory project for the bigger UNIX projects that will appear later on in the cursus.

To run project in terminal from main miniTalk direcectory use Make m or Make bonus, bother utilise the same code as I
worked both for to support Unicode. 

Two terminal windows need to be open, running ./server in one which should provide the process id number. In second
window running ./client (the PID) follwed by the message surrounded by " ". e.g
./client 29451 "hey there". this should send the message to the server, which should be followed by a a confirmation
message sent back to the client side to confirm that message was sent and recieved successfully! 
