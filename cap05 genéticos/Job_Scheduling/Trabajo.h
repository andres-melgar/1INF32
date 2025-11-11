#ifndef JOB_SCHEDULING_TRABAJO_H
#define JOB_SCHEDULING_TRABAJO_H

class Trabajo {
private:
    int id;
    int tiempo;
public:
    Trabajo(int id, int tiempo);

    int get_id() const;

    void set_id(int id);

    int get_tiempo() const;

    void set_tiempo(int tiempo);
};


#endif //JOB_SCHEDULING_TRABAJO_H