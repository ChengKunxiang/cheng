# ifndef MOTOR_HEADER
# define MOTOR_HEADER

namespace motor{
    class Motor{
        public:
            explicit Motor(int time);
            void ahead(int t);
            void left(int t);
            void right(int t);
            void back(int t);
            void stop(int t);
        private:
            int t = 10;
    };
}// namespace target

#endif // MOTOR_HEADER