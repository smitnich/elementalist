struct Mix_Chunk;
extern Mix_Chunk *snd_explode;
extern Mix_Chunk *snd_switch;
extern Mix_Chunk *snd_teleport;
extern Mix_Chunk *snd_spring;
extern Mix_Chunk *snd_splash;
bool playSound(Mix_Chunk *input);
void musicInit();
void setPanning(unsigned int channel, unsigned int right);
Mix_Music* loadMusic(char *fileName);
extern Mix_Music *titleMusic;
void freeMusic(int levelNum);
void playMusic(int levelNum);
void playMusic(Mix_Music *music);