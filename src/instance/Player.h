const Uint8 *state = SDL_GetKeyboardState(NULL);
class Player: public Entity {
    public:

        Player (float x, float y, World * world) : Entity (x, y, world) {
            this->w = 12;
            this->h = 28;
            this->type = "player1";
        }

        void placeBlock(int bx, int by, BlockType * type) {
        }

        void tick (float delta) {
        }

        void draw (float delta) {
            glDisable(GL_TEXTURE_2D);
            glColor3f(1.0f, 0.0f, 0.0f);
            glPushMatrix();
            glTranslatef(x, y, -1.0f);

            glBegin(GL_LINE_LOOP);

            glVertex2f(0.0f, 0.0f);
            glVertex2f(this->w, 0.0f);
            glVertex2f(this->w, this->h);
            glVertex2f(0.0f, this->h);

            glEnd();

            glPopMatrix();
            glEnable(GL_TEXTURE_2D);
        }
};
