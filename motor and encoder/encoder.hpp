# ifndef ENCODER_H
# define ENCODER_H
# include <Arduino.h>

namespace Encoder_Space{
    class Encoder{
        public:
            void start();
            void doEncoderA();
            void doEncoderB();
            void output_velocity();
            void output_position();
            void timer();
        private:
             volatile int encoderCounter;
    };
}

#endif