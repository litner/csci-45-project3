#include "./../header_files/random_player.h"

RandomPlayer::RandomPlayer(void) { }

RandomPlayer::~RandomPlayer(void) { }

void RandomPlayer::play(int mp3) {
  switch(mp3) {
    case 1:
      system("omxplayer /home/pi/csci-45-project3/mp3s/1.mp3");
      break;
    case 2:
      system("omxplayer /home/pi/csci-45-project3/mp3s/2.mp3");
      break;
    case 3:
      system("omxplayer /home/pi/csci-45-project3/mp3s/3.mp3");
      break;
    case 4:
      system("omxplayer /home/pi/csci-45-project3/mp3s/4.mp3");
      break;
    case 5:
      system("omxplayer /home/pi/csci-45-project3/mp3s/5.mp3");
      break;
    case 6:
      system("omxplayer /home/pi/csci-45-project3/mp3s/6.mp3");
      break;
    case 7:
      system("omxplayer /home/pi/csci-45-project3/mp3s/7.mp3");
      break;
    case 8:
      system("omxplayer /home/pi/csci-45-project3/mp3s/8.mp3");
      break;
    case 9:
      system("omxplayer /home/pi/csci-45-project3/mp3s/9.mp3");
      break;
    case 10:
      system("omxplayer /home/pi/csci-45-project3/mp3s/10.mp3");
      break;
    case 11:
      system("omxplayer /home/pi/csci-45-project3/mp3s/11.mp3");
      break;
  }
}
