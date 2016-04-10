class Note
{
    int buzzerPin=9;
    int note=3;
    int frequency;
    int duration;

    public: Note(char n[],int d)
    {
      pinMode(9,OUTPUT);
      switch (n[0])
      {
        case 'C':
          note+=1;
          break;
        case 'D':
          note+=3;
          break;
        case 'E':
          note+=4;
          break;
        case 'F':
          note+=6;
          break;
        case 'G':
          note+=8;
          break;
        case 'A':
          note+=9;
          break;
        case 'B':
          note+=11;
          break;
      }
      switch (n[1])
      {
        case '0':
          note-=12;
          break;
        case '1':
          note+=0;
          break;
        case '2':
          note+=12;
          break;
        case '3':
          note+=24;
          break;
        case '4':
          note+=36;
          break;
        case '5':
          note+=48;
          break;
        case '6':
          note+=60;
          break;
        case '7':
          note+=72;
          break;
        case '8':
          note+=82;
          break;
      }
      duration=d;
    }
    void calcNote()
    {
      frequency=(int)round(pow(2,(note-49.0)/12)*440);
    }
    void play()
    {
      
      tone(buzzerPin,frequency,duration);
      
    }
};

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

char NoteValueString[3];
int noteDuration;

void loop() {
  getNoteValue();
  Note n(NoteValueString,10000);
  n.calcNote();
  n.play();
}

void getNoteValue();
{
  int i=0;
  while (i<3)
  {
    if(Serial.available()>0)
    {
      NoteValueString[i]=(char)Serial.read();
      i++;
    }
  }
}

void getNoteDuration()
{
  char NoteDurationS[4];
  int i=0;
  while (i<4)
  {
    if(Serial.available()>0)
    {
      char d=(char)Serial.read();
      if(d!='.')
      {
        NoteDurationS[i]=d;
        i++;
      }
    }
  }
  
}
