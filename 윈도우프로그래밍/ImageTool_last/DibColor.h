#pragma once

void DibGrayscale(CDib& dib);

void RGB_TO_HSI(double R, double G, double B, double& H, double& S, double& I);
void HSI_TO_RGB(double H, double S, double I, double& R, double& G, double& B);

void RGB_TO_YUV(BYTE R, BYTE G, BYTE B, BYTE& Y, BYTE& U, BYTE& V);
void YUV_TO_RGB(BYTE Y, BYTE U, BYTE V, BYTE& R, BYTE& G, BYTE& B);

void DibColorSplitRGB(CDib& dib, CDib& dibR, CDib& dibG, CDib& dibB);
void DibColorSplitHSI(CDib& dib, CDib& dibH, CDib& dibS, CDib& dibI);
void DibColorSplitYUV(CDib& dib, CDib& dibY, CDib& dibU, CDib& dibV);

BOOL DibColorCombineRGB(CDib& dibR, CDib& dibG, CDib& dibB, CDib& dib);
BOOL DibColorCombineHSI(CDib& dibH, CDib& dibS, CDib& dibI, CDib& dib);
BOOL DibColorCombineYUV(CDib& dibY, CDib& dibU, CDib& dibV, CDib& dib);

void DibColorEdge(CDib& dib);
double CalcDist(double x, double y, double z);

void DibColorHistEqual(CDib& dib);
