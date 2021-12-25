namespace morse{
  #define piezo 8
  int incoming;
  String decodeToPtLetter;
  char space = ' ';
  
  void dot(){
    //dot
    digitalWrite(piezo, HIGH);
    delay(250);
    digitalWrite(piezo, LOW);
    delay(650);
  }
  void dash(){
    //dash
    digitalWrite(piezo, HIGH);
    delay(500);
    digitalWrite(piezo, LOW);
    delay(650);
  }

  String morse[26] = {"dot dash","dash dot dot dot", "dash dot dash dot", "dash dot dot", "dot", "dot dot dash dot", "dash dash dot",
                        "dot dot dot dot", "dot dot", "dot dash dash dash", "dash dot dash", "dot dash dot dot", "dash dash",
                        "dash dot", "dash dash dash", "dot dash dash dot", "dash dash dot dash", "dot dash dot", "dot dot dot", "dash",
                        "dot dot dash", "dot dot dot dash", "dot dash dash", "dash dot dot dash", "dash dot dash dash", "dash dash dot dot"};
  
  void decodeMorse(){
    //letter check
    for(int i=97; i<=122; i++){
      if(incoming==i){
        Serial.println(morse[i-97]);
        //morsefy
        for(int j=0; j<morse[i-97].length(); j++){
          if(j==2){
            decodeToPtLetter = morse[i-97].substring(1, 2);
          }else{
            decodeToPtLetter = morse[i-97].substring(j-1, j);
          }
          
        if(decodeToPtLetter=="o"){ dot(); }
        else if(decodeToPtLetter=="a"){ dash(); }
        }
      }      
    }
  }
}
