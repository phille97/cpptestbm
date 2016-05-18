
extern const int WIDTH;
extern const int HEIGHT;

class Block : public Instance {
    public:
        BlockType * type;
        int cdn;
        int tx;
        int ty;
        int deg;
        float R, G, B;

        Block (float x, float y, BlockType * type) : Instance(x, y) {
            this->h = 5;
            this->w = 5;
            this->tx = 5;
            this->ty = 5;
            this->deg = 0;
            this->R = (rand()%(255-0 + 1) + 0);
            this->G = (rand()%(255-0 + 1) + 0);
            this->B = (rand()%(255-0 + 1) + 0);
            setType(type);
        }

        ~Block () {
            delete type;
            cout << "block del" << endl;
        }

        void setType(BlockType * type) {
            this->type = &*type;
        }

        void tick(float delta) {
            if (this->x == this->tx && this->y == this->ty)
            {
                this->tx = (rand()%(WIDTH-0 + 1) + 0);
                this->ty = (rand()%(HEIGHT-0 + 1) + 0);
            }
            if(this->tx > this->x){
                this->x++;
            }else if(this->tx < this->x){
                this->x--;
            }
            if(this->ty > this->y){
                this->y++;
            }else if(this->ty < this->y){
                this->y--;
            }
            this->deg++;
            if(this->deg > 360) this->deg = 0;
        }

        void draw(float delta) {
            glDisable(GL_TEXTURE_2D);
            glColor3f(this->R/255.0f, this->G/255.0f, this->B/255.0f);

            glPushMatrix();

            glTranslatef(this->x, this->y, 0.0f);
                
            glRotatef((float)this->deg, 0.0f, 0.0f, 1.0f);

            glBegin(GL_QUADS);

            glVertex2f(0.0f, 0.0f);


            glTexCoord2f(0.0f, 1.0f);
            glVertex2f(0.0f, this->h);

            glTexCoord2f(1.0f, 1.0f);
            glVertex2f(this->w, this->h);


            glTexCoord2f(1.0f, 0.0f);
            glVertex2f(this->w, 0.0f);

            glEnd();
            glPopMatrix();

        }
};
