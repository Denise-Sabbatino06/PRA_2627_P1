#include <stdexcept>
#include "Square.h"

bool Square::check(Point2D* vertices) {
    double l = Point2D::distance(vertices[0], vertices[1]);
    return l == Point2D::distance(vertices[1], vertices[2])
        && l == Point2D::distance(vertices[2], vertices[3])
        && l == Point2D::distance(vertices[3], vertices[0]);
}

Square::Square() : Rectangle() {
    vs[0] = Point2D(-1, 1);
    vs[1] = Point2D(1, 1);
    vs[2] = Point2D(1, -1);
    vs[3] = Point2D(-1, -1);
}

Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid square!");
    }
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid square!");
    }
    Rectangle::set_vertices(vertices);
}

void Square::print() {
    std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream &out, const Square &s) {
    out << "[Square: color = " << s.get_color();
    for (int i = 0; i < Rectangle::N_VERTICES; i++) {
        out << "; v" << i << " = " << s.get_vertex(i);
    }
    out << "]";
    return out;
}
