#include <EEPROM.h>

void setup()
{
  Serial.begin(9600);
}

/*
 function: writes data to EEPROM in little endian order
 params: bigData(int, data to be written),
      address(int, starting address)
*/
bool writeInt(int bigData, int address)  {
  byte littleData;
  //masking bigData for 8-LSBs
  littleData = bigData & 0xFF;
  EEPROM.write(address, littleData);
  //right shift 8 bits for 8-MSBs
  littleData = (bigData >> 8);
  EEPROM.write(address+1, littleData);
  return true;
}

/*
 function: writes data to EEPROM in little endian order
 params: bigData(long, data to be written),
      address(int, starting address)
*/
bool writeLong(long bigData, int address)  {
  byte littleData;
  int len = sizeof(bigData);
  int byteSize = 8;
  littleData = bigData & 0xFF;
  EEPROM.write(address, littleData);  //1st byte written
  for(int i = 1; i<len; i++)  {       //loops to write other bytes
    littleData = (bigData >> i*byteSize);
    EEPROM.write(address+i, littleData);
  }
  return true;
}

/*
 function: writes data to EEPROM in little endian order
 params: bigData(unsigned long, data to be written),
      address(int, starting address)
*/
bool writeUL(unsigned long bigData, int address)  {
  byte littleData;
  int len = sizeof(bigData);
  int byteSize = 8;
  littleData = bigData & 0xFF;
  EEPROM.write(address, littleData);  //1st byte written
  for(int i = 1; i<len; i++)  {       //loops to write other bytes
    littleData = (bigData >> i*byteSize);
    EEPROM.write(address+i, littleData);
  }
  return true;
}

/*
 function: writes data to EEPROM in little endian order
 params: bigData(long long, data to be written),
      address(int, starting address)
*/
bool writeLL(long long bigData, int address)  {
  byte littleData;
  int len = sizeof(bigData);
  int byteSize = 8;
  littleData = bigData & 0xFF;
  EEPROM.write(address, littleData);  //1st byte written
  for(int i = 1; i<len; i++)  {       //loops to write other bytes
    littleData = (bigData >> i*byteSize);
    EEPROM.write(address+i, littleData);
  }
  return true;
}

void readInt(int address) {
  //todo
}

void write_() {
  bool flag;
  int ch, addr;
  Serial.println("\n1)int \n2)long \n3)unsigned long \n4)long long");
  Serial.print("Enter the datatype: ");
  while(Serial.available()==0) {}
  ch = Serial.parseInt();
  Serial.println(ch);
  Serial.print("Enter the address: ");
  while(Serial.available()==0) {}
  addr = Serial.parseInt();
  Serial.println(addr);
  Serial.print("Enter the data: ");
  switch(ch)  {
    case 1: while(Serial.available()==0) {}
            int data = Serial.parseInt();
            Serial.println(data);
            flag=writeInt(data, addr);
            if(flag)  {
              Serial.print(data);
              Serial.print(" written successfully to address ");
              Serial.println(addr);
            }
            break;
    case 2: while(Serial.available()==0) {}
            long data = Serial.read();
            Serial.println(data);
            flag=writeLong(data, addr);
            if(flag)  {
              Serial.print(data);
              Serial.print(" written successfully to address ");
              Serial.println(addr);
            }
            break;
    case 3: while(Serial.available()==0) {}
            unsigned long data = Serial.read();
            Serial.println(data);
            flag=writeUL(data, addr);
            if(flag)  {
              Serial.print(data);
              Serial.print(" written successfully to address ");
              Serial.println(addr);
            }
            break;
    case 4: while(Serial.available()==0) {}
            long long data = Serial.read();
            Serial.println(data);
            flag=writeLL(data, addr);
            if(flag)  {
              Serial.print(data);
              Serial.print(" written successfully to address ");
              Serial.println(addr);
            }
            break;
    default: Serial.println("Incorrect choice! Enter again!");
  }
}

void read_()  {
  int ch, addr;
  Serial.println("\n1)int \n2)long \n3)unsigned long \n4)long long");
  Serial.print("Enter the datatype: ");
  while(Serial.available()==0) {}
  ch = Serial.parseInt();
  Serial.print("Enter the address: ");
  while(Serial.available()==0) {}
  addr = Serial.parseInt();
  Serial.println(addr);
  Serial.print("Data stored at ");
  Serial.print(addr);
  Serial.print(" is: ");
  switch(ch)  {
    case 1: //Serial.println(readInt(addr), DEC);
            break;
    case 2: //Serial.println(readlong(addr), DEC);
            break;
    case 3: //Serial.println(readUlong(addr), DEC);
            break;
    case 4: //Serial.println(readLL(addr), DEC);
            break;
    default: Serial.println("Incorrect choice! Enter again!");
  }
}

bool askChoice()  {
  bool flag = true;
  int ch;
  Serial.println("1) Write\n2) Read");
  Serial.print("Enter choice: ");
  while(Serial.available()==0)  {}
  ch = Serial.parseInt();
  Serial.println(ch);
  switch(ch)  {
    case 1: write_();
            break;
    case 2: read_();
            break;
    default: Serial.println("Incorrect choice! Enter again");
             flag=false;
             break;
  }
  return flag;
}

void loop()
{
  bool flag = false;
  while(!flag)  {
    flag = askChoice();
    Serial.println();
  }
}
