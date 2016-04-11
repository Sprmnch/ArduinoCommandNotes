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
      switch (n[2])
      {
        case 'F':
          note-=1;
          break;
        case 'S':
          note+=1;
      }
      duration=d;
      Serial.println(note);
      Serial.println(duration);
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
  Serial.begin(9600);
}

char noteValueString[3];
int noteDuration;

void getNoteValue()
{
  int i=0;
  while (i<3)
  {
    if(Serial.available()>0)
    {
      noteValueString[i]=(char)Serial.read();
      i++;
    }
  }
}

void getNoteDuration()
{
  noteDuration=0;
  boolean aquiredInt=true;
  while(aquiredInt)
  {
    if(Serial.available()>0)
    {
      noteDuration=Serial.parseInt();
      aquiredInt=false;
    }
  }
}

void loop() {
  getNoteValue();
  getNoteDuration();
  Note n(noteValueString,noteDuration);
  n.calcNote();
  n.play();
}


