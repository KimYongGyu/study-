#pragma once

void DibInverse(CDib& dib);
void DibBrightness(CDib& dib, int n);
void DibContrast(CDib& dib, int n);
void DibGammaCorrection(CDib& dib, float gamma);
void DibHistogram(CDib& dib, float histo[256]);
void DibHistEqual(CDib& dib);

BOOL DibAdd(CDib& dib1, CDib& dib2, CDib& dib3);
BOOL DibSub(CDib& dib1, CDib& dib2, CDib& dib3);
BOOL DibAve(CDib& dib1, CDib& dib2, CDib& dib3);
BOOL DibDif(CDib& dib1, CDib& dib2, CDib& dib3);
BOOL DibAND(CDib& dib1, CDib& dib2, CDib& dib3);
BOOL DibOR(CDib& dib1, CDib& dib2, CDib& dib3);

void DibBitPlane(CDib& dib1, int bit, CDib& dib2);
