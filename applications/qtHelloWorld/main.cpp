#include <QApplication>
#include "codeeditor.h"

int main( int argc, char** argv )
{
    QApplication app( argc, argv );

    CodeEditor editor;
    editor.setWindowTitle( QObject::tr( "Code Editor Example" ) );
    editor.show( );

    return app.exec( );
}
