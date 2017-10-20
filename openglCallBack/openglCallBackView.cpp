
// openglCallBackView.cpp : implementation of the CopenglCallBackView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "openglCallBack.h"
#endif

#include "openglCallBackDoc.h"
#include "openglCallBackView.h"
#include "math.h"
#include <vector>

#include "..//dependence//glm//glm.hpp"
#include "..//dependence//glm//vec3.hpp"
#include "..//dependence//glm//vec4.hpp"
#include "..//dependence//glm//mat4x4.hpp"
#include "..//dependence//glm//gtc//matrix_transform.hpp"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define  WindowWidth 256;
#define  WindowHeight 256;
int width,height;



#pragma comment( lib, "OpenGL32.lib" )
#pragma comment( lib, "glu32.lib" )

double angleY = 0.0;
double angleX = 0.0;
std::vector<GLfloat> rotateVector(3);

double rotateAngle = 0.0;

GLfloat RotateMatrix[16] = { 1,0,0,0,
                             0,1,0,0,
                             0,0,1,0,
                             0,0,0,1
                           };

GLfloat cubeAlpha = 0.5f;
GLfloat planeAlpha = 0.3f;

// CopenglCallBackView




void drawCube()
{
    GLdouble plane0[4] = {-1.0f,-1.0f,-1.0f,1.5f};
    
    //glEnable( GL_DEPTH_TEST );
    glEnable( GL_STENCIL_TEST );
    glStencilFunc( GL_ALWAYS, 1, 0xFF );
    glStencilOp( GL_KEEP, GL_KEEP, GL_INVERT );

    glEnable( GL_LINE_SMOOTH );
    glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    /*glEnable( GL_CULL_FACE );
    glCullFace( GL_BACK );
    glFrontFace( GL_CCW );
    glPolygonMode( GL_FRONT, GL_FILL );*/
    glDisable( GL_CULL_FACE );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( -0.5f,-0.5f, -6.0f );
    glTranslatef( 0.5f,0.5f, 0.5f );
    glMultMatrixf( RotateMatrix );
    glTranslatef( -0.5f,-0.5f, -0.5f );
    glBegin(GL_QUADS);
        //front face
        glColor4f( 0.0f,0.0f,1.0f ,cubeAlpha);
        glVertex3f( 0.0f,0.0f,1.0f );
        glColor4f( 1.0f,0.0f,1.0f ,cubeAlpha);
        glVertex3f( 1.0f,0.0f,1.0f );
        glColor4f( 1.0f,1.0f,1.0f ,cubeAlpha);
        glVertex3f( 1.0f,1.0f,1.0f );
        glColor4f( 0.0f,1.0f,1.0f ,cubeAlpha);
        glVertex3f( 0.0f,1.0f,1.0f );

        //left face
        glColor4f( 0.0f,0.0f,1.0f ,cubeAlpha);
        glVertex3f( 0.0f,0.0f,1.0f );
        glColor4f( 0.0f,1.0f,1.0f ,cubeAlpha);
        glVertex3f( 0.0f,1.0f,1.0f );
        glColor4f( 0.0f,1.0f,0.0f ,cubeAlpha);
        glVertex3f( 0.0f,1.0f,0.0f );
        glColor4f( 0.0f,0.0f,0.0f ,cubeAlpha);
        glVertex3f( 0.0f,0.0f,0.0f );

        // top face
        glColor4f( 0.0f,1.0f,1.0f ,cubeAlpha);
        glVertex3f( 0.0f,1.0f,1.0f );
        glColor4f( 1.0f,1.0f,1.0f ,cubeAlpha);
        glVertex3f( 1.0f,1.0f,1.0f );
        glColor4f( 1.0f,1.0f,0.0f ,cubeAlpha);
        glVertex3f( 1.0f,1.0f,0.0f );
        glColor4f( 0.0f,1.0f,0.0f ,cubeAlpha);
        glVertex3f( 0.0f,1.0f,0.0f );

        //right face
        glColor4f( 1.0f,1.0f,1.0f ,cubeAlpha);
        glVertex3f( 1.0f,1.0f,1.0f );
        glColor4f( 1.0f,0.0f,1.0f ,cubeAlpha);
        glVertex3f( 1.0f,0.0f,1.0f );
        glColor4f( 1.0f,0.0f,0.0f ,cubeAlpha);
        glVertex3f( 1.0f,0.0f,0.0f );
        glColor4f( 1.0f,1.0f,0.0f ,cubeAlpha);
        glVertex3f( 1.0f,1.0f,0.0f );

        // bottom face
        glColor4f( 0.0f,0.0f,1.0f ,cubeAlpha);
        glVertex3f( 0.0f,0.0f,1.0f );
        glColor4f( 0.0f,0.0f,0.0f ,cubeAlpha);
        glVertex3f( 0.0f,0.0f,0.0f );
        glColor4f( 1.0f,0.0f,0.0f ,cubeAlpha);
        glVertex3f( 1.0f,0.0f,0.0f );
        glColor4f( 1.0f,0.0f,1.0f ,cubeAlpha);
        glVertex3f( 1.0f,0.0f,1.0f );

        // back face
        glColor4f( 0.0f,0.0f,0.0f ,cubeAlpha);
        glVertex3f( 0.0f,0.0f,0.0f );
        glColor4f( 0.0f,1.0f,0.0f ,cubeAlpha);
        glVertex3f( 0.0f,1.0f,0.0f );
        glColor4f( 1.0f,1.0f,0.0f ,cubeAlpha);
        glVertex3f( 1.0f,1.0f,0.0f );
        glColor4f( 1.0f,0.0f,0.0f ,cubeAlpha);
        glVertex3f( 1.0f,0.0f,0.0f );
    glEnd();

    //sagittal plane of the cube center
    /*glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    glDisable( GL_CULL_FACE );
    glBegin( GL_QUADS );
    glColor4f( 0.0f,0.0f,1.0f ,planeAlpha);
    glVertex3f( 0.5f, -0.5f,1.5f );
    glVertex3f( 0.5f,-0.5f,-0.5f );
    glVertex3f( 0.5f,1.5f, -0.5f);
    glVertex3f( 0.5f,1.5f,1.5f );

    glEnd();*/

    glClipPlane( GL_CLIP_PLANE0, plane0 );
    glEnable( GL_CLIP_PLANE0);

    //glFinish();

    //glDisable( GL_CLIP_PLANE0 );
    glDisable( GL_DEPTH_TEST );
    glStencilFunc( GL_NOTEQUAL, 0x0,0xFF );
    glStencilOp( GL_KEEP, GL_KEEP, GL_KEEP );
    /*glBegin( GL_QUADS );
    glColor3f( 1.0f,0.0f,0.0f );
    glVertex3f( -10.0f,-10.0f, -2.0f );
    glVertex3f( 10.0f,-10.0f, -2.0f );
    glVertex3f( 10.0f,10.0f, -2.0f );
    glVertex3f( -10.0f,10.0f, -2.0f );

    glEnd();*/

    glEnable( GL_CULL_FACE );
    glFrontFace( GL_CCW );
    glCullFace( GL_BACK );
    glBegin( GL_TRIANGLES );
    glColor3f( 1.0f,0.0f,0.0f );
    glVertex3f( 0.0f,0.0f,1.48f );
    glVertex3f( 1.48f,0.0f,0.0f );
    glVertex3f( 0.0f,1.48f,0.0f );
    glEnd();

}

void drawTriangles()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glEnable( GL_CULL_FACE );
    glFrontFace( GL_CCW );
    glCullFace( GL_BACK );
    glPolygonMode( GL_FRONT, GL_FILL );
    glEnable( GL_POLYGON_OFFSET_FILL );
    glPolygonOffset( 1.0f,1.0f );
    glBegin( GL_TRIANGLES );
        glColor3f( 1.0f,0.0f,0.0f );
        glVertex3f( 0.0f, 1.0f, -3.5f );
        //glColor3f( 0.0f,1.0f,0.0f );
        glVertex3f( -0.5, -1.0f, -3.5f );
        //glColor3f( 0.0f,0.0f,1.0f );
        glVertex3f( 0.5f,-1.0f,-3.5f );
    glEnd();


    //Line
    glPolygonMode( GL_FRONT, GL_LINE );
    glEnable( GL_POLYGON_OFFSET_LINE );
    glPolygonOffset( 0.0f, 1.0f );
    glBegin( GL_TRIANGLES );
        glColor3f( -0.0f,1.0f,0.0f );
        glVertex3f( 0.0f, 1.0f, -3.5f );
        //glColor3f( 0.0f,1.0f,0.0f );
        glVertex3f( -0.5, -1.0f, -3.5f );
        //glColor3f( 0.0f,0.0f,1.0f );
        glVertex3f( 0.5f,-1.0f,-3.5f );
    glEnd();

}

IMPLEMENT_DYNCREATE(CopenglCallBackView, CView)

BEGIN_MESSAGE_MAP(CopenglCallBackView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CopenglCallBackView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
    ON_WM_CREATE()
    ON_WM_DESTROY()
    ON_WM_SIZE()
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    ON_WM_MOVE()
    ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


class CopenglCallBackView::mathImpl
{
public:
    mathImpl(){};
    ~mathImpl(){};
    std::vector<GLfloat> crossVector( const std::vector<GLfloat> firstVector, const std::vector<GLfloat> secondVector )
    {
        std::vector<GLfloat> crossResult(3);
        crossResult[0] = firstVector[1]*secondVector[2] - firstVector[2]*secondVector[1];
        crossResult[1] = firstVector[2]*secondVector[0] - firstVector[0]*secondVector[2];
        crossResult[2] = firstVector[0]*secondVector[1] - firstVector[1]*secondVector[0];
        return crossResult;
    }

    void calculateRotateMatrix( )
    {
        glm::mat4x4 IdentityMatrix;
        glm::vec3 directionVector( rotateVector[0],rotateVector[1],rotateVector[2] );
        IdentityMatrix = glm::rotate( IdentityMatrix, (float)rotateAngle, directionVector );

        glm::mat4x4 preRotateMatrix;

        toglmMatrix( RotateMatrix, preRotateMatrix );

        IdentityMatrix = IdentityMatrix * preRotateMatrix;

        toGLfloatMatrix( RotateMatrix, IdentityMatrix );

    }

    void toGLfloatMatrix( GLfloat* glfoatMatrix, glm::mat4x4 glmMatrix )
    {
        for( int i = 0; i<4; ++i )
        {
            for( int j = 0; j<4; ++j )
            {
                glfoatMatrix[ i*4+j ] = glmMatrix[i][j];
            }
        }
    }

    void toglmMatrix( GLfloat* glfloatMatrix, glm::mat4x4& glmMatrix )
    {
        for( int i = 0; i<4; ++i )
        {
            for( int j = 0; j<4; ++j )
            {
                glmMatrix[i][j] = glfloatMatrix[ i*4+j ];
            }
        }
    }

};

// CopenglCallBackView construction/destruction

CopenglCallBackView::CopenglCallBackView()
{
	// TODO: add construction code here
    m_bLButtonDown = false;
    rotateVector[0] = 0.0f;
    rotateVector[1] = 0.0f;
    rotateVector[2] = 1.0f;
}

CopenglCallBackView::~CopenglCallBackView()
{
}

BOOL CopenglCallBackView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CopenglCallBackView drawing

void CopenglCallBackView::OnDraw(CDC* /*pDC*/)
{
	CopenglCallBackDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
    static BOOL bBusy = FALSE;	//定义开关变量
	//开关，使绘制完成后才可更新缓存
	if( bBusy )
	{
		return;			
	}
	bBusy = TRUE;
	// TODO: add draw code for native data here
    glClearColor( 0.5f,0.5f,0.5f ,1.0f);
    glClearStencil( 0x0 );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );

    drawCube();
    //drawTriangles();
    glFinish();

    SwapBuffers( wglGetCurrentDC() );

    bBusy = FALSE;

}


// CopenglCallBackView printing


void CopenglCallBackView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CopenglCallBackView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CopenglCallBackView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CopenglCallBackView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CopenglCallBackView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CopenglCallBackView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CopenglCallBackView diagnostics

#ifdef _DEBUG
void CopenglCallBackView::AssertValid() const
{
	CView::AssertValid();
}

void CopenglCallBackView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CopenglCallBackDoc* CopenglCallBackView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CopenglCallBackDoc)));
	return (CopenglCallBackDoc*)m_pDocument;
}
#endif //_DEBUG


// CopenglCallBackView message handlers


int CopenglCallBackView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CView::OnCreate(lpCreateStruct) == -1)
        return -1;

    // TODO:  Add your specialized creation code here
    GLsetting();
    return 0;
}


void CopenglCallBackView::OnDestroy()
{
    CView::OnDestroy();

    // TODO: Add your message handler code here

    HGLRC glRC = wglGetCurrentContext();

    wglMakeCurrent( NULL, NULL );

    if(glRC)
    {
        wglDeleteContext( glRC );
    }
    if( m_pClientDC )
    {
        delete m_pClientDC;
    }
}


void CopenglCallBackView::OnSize(UINT nType, int cx, int cy)
{
    CView::OnSize(nType, cx, cy);

    // TODO: Add your message handler code here
    width = cx;
    height = cy;
    if( cy > 0 )
    {
        glViewport( 0,0, (GLsizei)cx, (GLsizei)cy );

        glMatrixMode( GL_PROJECTION );
        glLoadIdentity();
        gluPerspective( 45, cx/cy, 1.0f, 30.0f );
    }
    RedrawWindow();
}


void CopenglCallBackView::GLsetting()
{
    m_pClientDC = new CClientDC(this);
    HGLRC glRC;

    //glRC = wglCreateContext( m_pClientDC->GetSafeHdc() );

    if( !PixelFormatSetting() )
        return;

    glRC = wglCreateContext( m_pClientDC->GetSafeHdc() );
    wglMakeCurrent( m_pClientDC->GetSafeHdc(), glRC );

}

bool CopenglCallBackView::PixelFormatSetting()
{
    static PIXELFORMATDESCRIPTOR pfd = 
    {
        sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | 
         PFD_SUPPORT_OPENGL | 
         PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		24,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		32, 
		8, 0,
		PFD_MAIN_PLANE,
		0, 0, 0, 0
    };

    int pfdID ;

    if( (pfdID = ChoosePixelFormat( m_pClientDC->GetSafeHdc(), &pfd )) == 0 )
    {
        MessageBox( _T("choosepixelformation fail") );
        return FALSE;
    }

    if( SetPixelFormat( m_pClientDC->GetSafeHdc(), pfdID, &pfd ) == FALSE )
    {
        MessageBox( _T("setpixelformation fail") );
        return FALSE;
    }

    return TRUE;
}


void CopenglCallBackView::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default
    m_pStartLocation = point;
    m_bLButtonDown = true;
    CView::OnLButtonDown(nFlags, point);
}


void CopenglCallBackView::OnLButtonUp(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default
    /*angleX = (point.y - m_pStartLocation.y)/height * 360;
    angleY = (point.x - m_pStartLocation.x)/width * 360;*/

    m_bLButtonDown = false;

    /*angleX = (point.y - m_pStartLocation.y);
    angleY = (point.x - m_pStartLocation.x);

    rotateAngle = sqrtf( angleX*angleX + angleY*angleY );

    double mouseDirection[3] = { point.x - m_pStartLocation.x, point.y - m_pStartLocation.y,0 };

    double viewDirection[3] = { 0.0,0.0,1.0 };

    rotateVector[0] = mouseDirection[1]*viewDirection[2] - mouseDirection[2]*viewDirection[1];
    rotateVector[1] = mouseDirection[2]*viewDirection[0] - mouseDirection[0]*viewDirection[2];
    rotateVector[2] = mouseDirection[0]*viewDirection[1] - mouseDirection[1]*viewDirection[0];

    RedrawWindow();*/
    CView::OnLButtonUp(nFlags, point);
    //RedrawWindow();
}


void CopenglCallBackView::OnMove(int x, int y)
{
    CView::OnMove(x, y);

    // TODO: Add your message handler code here
    /*if( m_bLButtonDown )
    {
        angleX = (y - m_pStartLocation.y);
        angleY = (x - m_pStartLocation.x);

        rotateAngle = sqrtf( angleX*angleX + angleY*angleY );

        double mouseDirection[3] = { x - m_pStartLocation.x, y - m_pStartLocation.y,0 };

        double viewDirection[3] = { 0.0,0.0,1.0 };

        rotateVector[0] = mouseDirection[1]*viewDirection[2] - mouseDirection[2]*viewDirection[1];
        rotateVector[1] = mouseDirection[2]*viewDirection[0] - mouseDirection[0]*viewDirection[2];
        rotateVector[2] = mouseDirection[0]*viewDirection[1] - mouseDirection[1]*viewDirection[0];

        RedrawWindow();
    }*/
}


void CopenglCallBackView::OnMouseMove(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default
    if( m_bLButtonDown && point != m_pStartLocation )
    {
        angleX = (point.y - m_pStartLocation.y);
        angleY = (point.x - m_pStartLocation.x);

        rotateAngle = sqrtf( angleX*angleX + angleY*angleY );

        rotateAngle = abs(rotateAngle) < 1 ? 1 : rotateAngle;

        //double mouseDirection[3] = { point.x - m_pStartLocation.x, point.y - m_pStartLocation.y,0 };

        std::vector<GLfloat> mouseDirection(3);
        mouseDirection[0] = point.x - m_pStartLocation.x;
        mouseDirection[1] = m_pStartLocation.y - point.y;
        mouseDirection[2] = 0;

        std::vector<GLfloat> viewDirection(3);
        viewDirection[0] = 0.0;
        viewDirection[1] = 0.0;
        viewDirection[2] = 1.0;

        /*rotateVector[0] = mouseDirection[1]*viewDirection[2] - mouseDirection[2]*viewDirection[1];
        rotateVector[1] = mouseDirection[2]*viewDirection[0] - mouseDirection[0]*viewDirection[2];
        rotateVector[2] = mouseDirection[0]*viewDirection[1] - mouseDirection[1]*viewDirection[0];

        rotateVector[0] = -rotateVector[0];
        rotateVector[1] = -rotateVector[1];
        rotateVector[2] = -rotateVector[2];*/

        rotateVector = m_pMathImpl->crossVector( viewDirection, mouseDirection );
        m_pMathImpl->calculateRotateMatrix( );

        m_pStartLocation = point;
        //RedrawWindow();
        Invalidate( FALSE );
    }
    CView::OnMouseMove(nFlags, point);
}


