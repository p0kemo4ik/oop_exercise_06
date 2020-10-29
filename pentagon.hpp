#include"vertex.hpp"
template <class T>
class Pentagon {
private:
    Vertex<T> Vertexs[5];
public:
    using vertex_type = Vertex<T>;
    Pentagon() = default;
    Pentagon(std::istream& in);
    void read(std::istream& in);
    Vertex<T> center() const;
    double square() const;
    void print(std::ostream& os) const;
    friend std::ostream& operator<< (std::ostream& out, const Pentagon<T>& point);
    friend std::ostream& operator>> (std::istream& in, const Pentagon<T>& point);
};


template<class T> Pentagon<T>::Pentagon(std::istream& in) {
    for (int i = 0; i < 5; i++)
        in >> Vertexs[i];
}
template<class T> double Pentagon<T>::square() const {
    double Area = 0;
    for (int i = 0; i < 5; i++) {
        Area += (Vertexs[i].x) * (Vertexs[(i + 1) % 5].y) - (Vertexs[(i + 1) % 5].x) * (Vertexs[i].y);
    }
    Area *= 0.5;
    return abs(Area);
}

template<class T> void Pentagon<T>::print(std::ostream& os) const {
    os << "Pentagon: ";
    for (int i = 0; i < 5; i++)

        os << Vertexs[i] << ' ';
    os << '\n';
}


template<class T> Vertex<T> Pentagon<T>::center() const {
    Vertex<T> res = Vertex<T>();
    for (int i = 0; i < 5; i++)
        res += Vertexs[i];
    res.x = res.x / 5;
    res.y = res.y / 5;
    return res;
}

template <class T> void Pentagon<T>::read(std::istream& in) {
    Pentagon<T> res = Pentagon(in);
    *this = res;
}

template<class T>
std::ostream& operator<< (std::ostream& out, const Pentagon<T>& point) {
    out << "Pentagon: ";
    for (int i = 0; i < 5; i++)
        out << point.Vertexs[i] << ' ';
    out << '\n';
    return out;
}

template<class T>
std::istream& operator>> (std::istream& in, const Pentagon<T>& point) {
    for (int i = 0; i < 5; i++)
        in >> point.Vertexs[i];
    return in;
}