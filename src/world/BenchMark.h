#include "../World.h"
#include "../Entity.h"
#include "../instance/Player.h"
#include <sys/time.h>

extern Uint32 currentFPS;

using namespace std;
class BenchMark: public World {
    public:
        long int ngr = 0;
        long int begin = 0;
        long int ball = 0;

        void tick(float delta) {
            tickInstances(delta);
            for (int i = 0; i < 100; ++i)
            {
                instances.insert(instances.begin(), new Block(0.0f, 0.0f, &BLOCK_GRASS));
            }
            struct timeval tp;
            gettimeofday(&tp, NULL);
            long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
            if(this->begin == 0){
                this->begin = ms;
            }
            if(this->ball + 5000 < ms){
                int elapsed = (ms - this->begin) / 1000;
                cout << "Time: " << elapsed << "sec, Total Nodes: "<< instances.size() << ", FPS: " << currentFPS << endl;
                this->ball = ms;
            }
            this->ngr = ms;
        }

        void tickInstances(float delta) {
            Instance *instance;
            for (instanceIterator = instances.begin() ; instanceIterator != instances.end(); instanceIterator++) {
                instance = &**instanceIterator;
                instance->tick(delta);
            }
        }

        void draw(float delta) {
            Instance *instance;
            for (instanceIterator = instances.begin() ; instanceIterator != instances.end(); instanceIterator++) {
                instance = &**instanceIterator;
                instance->draw(delta);
            }

        }

        void initialize(float delta) {
            instances.insert(instances.begin(), new Block(0.0f, 0.0f, &BLOCK_GRASS));
        }
};
