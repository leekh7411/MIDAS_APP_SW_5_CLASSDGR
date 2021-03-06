#include "stdafx.h"
#include "InheritanceLine.h"
#include <math.h>
#define PI 3.141592265

CPoint transformation(CPoint centerP, CPoint moveP, double angle);
InheritanceLine::InheritanceLine()
{
	drawMode = START;
}

InheritanceLine::InheritanceLine(CPoint centerPoint)
{
	startPoint = centerPoint;
	drawMode = START;
}
InheritanceLine::InheritanceLine(CPoint start, CPoint end) {
	drawMode = START;
	startPoint.SetPoint(start.x, start.y);
	endPoint.SetPoint(end.x, end.y);
}
void InheritanceLine::ReDraw(CDC* pDC) {
	//printf("InheritanceLine Line ReDraw (%d,%d) , (%d,%d)\n", startPoint.x, startPoint.y, endPoint.x, endPoint.y);
	pDC->MoveTo(startPoint.x, startPoint.y);
	pDC->LineTo(endPoint.x, endPoint.y);

	CPoint p1(endPoint.x - 20, endPoint.y + 20);
	CPoint p2(endPoint.x - 20, endPoint.y - 20);
	int x = endPoint.x - startPoint.x;
	int y = endPoint.y - startPoint.y;
	double angle = atan2(y, x);

	CPoint p1_new = transformation(endPoint, p1, angle);
	CPoint p2_new = transformation(endPoint, p2, angle);
	pDC->LineTo(p1_new.x, p1_new.y);
	pDC->LineTo(p2_new.x, p2_new.y);
	pDC->LineTo(endPoint.x, endPoint.y);
}

CPoint transformation(CPoint centerP, CPoint moveP, double angle)
{
	double rx = (moveP.x - centerP.x)*cos(angle) - (moveP.y - centerP.y)*sin(angle) + centerP.x;
	double ry = (moveP.x - centerP.x)*sin(angle) + (moveP.y - centerP.y)*cos(angle) + centerP.y;
	return CPoint((int)rx, (int)ry);
}

bool InheritanceLine::Draw(CPoint point, int flag, int dmode, CDC* pDC, std::vector<M_Polygon*>* saveList) {
	//printf("DRAW - Line\n");
	switch (dmode) {
	case L_MOUSE_UP: {
		//printf("마우스 업 \n");
		break;
	}
	case L_MOUSE_DOWN: {
		//printf("마우스 클릭 \n");
		drawMode = END;
		break;
	}
	case MOUSE_MOVE: {
		//printf("now..in inheritance draw line, move mouse ! \n");
		if (drawMode == END)break;
		if (drawMode != START && (saveList->size() != 0))saveList->pop_back();
		drawMode = MOVE;
		saveList->push_back(new InheritanceLine(startPoint, point));// save Polygon

		return true;
		
	}default: {
		break;
	}
	}
	return false;
}



InheritanceLine::~InheritanceLine()
{
}


void InheritanceLine::addConnectedPoint(CPoint* p, CPoint* q) {

}


void InheritanceLine::removeConnectedPoint() {

}

void InheritanceLine::reConnectedPoint() {

}

void InheritanceLine::saveData(CArchive& ar) {
	printf("Save InheritanceLine ! \n");
	if (ar.IsStoring()) {
		// save
		if (isVisual) {
			printf("save InheritanceLine (%d,%d) ~ (%d,%d)\n", startPoint.x, startPoint.y, endPoint.x, endPoint.y);
			ar << startPoint << endPoint;
		}
	}
	else {
		// load
		if (isVisual) {
			ar >> startPoint >> endPoint;
			printf("Load InheritanceLine (%d,%d) ~ (%d,%d)\n", startPoint.x, startPoint.y, endPoint.x, endPoint.y);
		}
	}
}
