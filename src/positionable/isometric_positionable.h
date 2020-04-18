#ifndef ISOMETRICMAPEDITOR_ISOMETRIC_POSITIONABLE
#define ISOMETRICMAPEDITOR_ISOMETRIC_POSITIONABLE


#include <gen/Node2D.hpp>
#include <core/Godot.hpp>

namespace godot {

#define GODOT_LOG(level, message)\
    switch (level) {\
        case 0:\
            Godot::print(message);\
            break;\
        case 1:\
            Godot::print_warning(message, BOOST_CURRENT_FUNCTION, __FILE__, __LINE__);\
            break;\
        case 2:\
            Godot::print_error(message, BOOST_CURRENT_FUNCTION, __FILE__, __LINE__);\
            break;\
    }\

    class IsometricPositionable : public Node2D {
    GODOT_CLASS(IsometricPositionable, Node2D)

    private:
        AABB aabb;
        int zOrderSize;

        PoolVector2Array leftPoints;
        PoolVector2Array rightPoints;
        PoolVector2Array upPoints;
        PoolVector2Array downPoints;

        void updateZOrderSize(int change);
    public:
        Vector2 isoPosition;

        IsometricPositionable();

        ~IsometricPositionable();
        static void _register_methods();
        void _enter_tree();
        void _exit_tree();

        Transform2D getHexagoneCoordinates();
        void drawOutline();

        AABB getAABB();
        void setAABB(AABB ab);
        int getZOrderSize();
        void setZOrderSize(int size);

        virtual void onResize(Vector3 size);
        virtual void gridUpdated(int stair);
        virtual void onSelect(bool isSelected);
    };
}

#endif //ISOMETRICMAPEDITOR_ISOMETRIC_POSITIONABLE