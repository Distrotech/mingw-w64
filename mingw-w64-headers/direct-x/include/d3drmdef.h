/*
 * Copyright 2007 Vijay Kiran Kamuju
 * Copyright 2007 David ADAM
 * Copyright 2010 Christian Costa
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __D3DRMDEFS_H__
#define __D3DRMDEFS_H__

#include <stddef.h>
#include <d3dtypes.h>

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct _D3DRMVECTOR4D
{
    D3DVALUE x;
    D3DVALUE y;
    D3DVALUE z;
    D3DVALUE w;
} D3DRMVECTOR4D, *LPD3DRMVECTOR4D;

typedef D3DVALUE D3DRMMATRIX4D[4][4];

typedef struct _D3DRMQUATERNION {
    D3DVALUE s;
    D3DVECTOR v;
} D3DRMQUATERNION, *LPD3DRMQUATERNION;

typedef struct _D3DRMRAY {
    D3DVECTOR dvDir;
    D3DVECTOR dvPos;
} D3DRMRAY, *LPD3DRMRAY;

typedef struct _D3DRMBOX {
    D3DVECTOR min;
    D3DVECTOR max;
} D3DRMBOX, *LPD3DRMBOX;

typedef enum _D3DRMLIGHTTYPE {
    D3DRMLIGHT_AMBIENT,
    D3DRMLIGHT_POINT,
    D3DRMLIGHT_SPOT,
    D3DRMLIGHT_DIRECTIONAL,
    D3DRMLIGHT_PARALLELPOINT
} D3DRMLIGHTTYPE, *LPD3DRMLIGHTTYPE;

typedef DWORD D3DRMRENDERQUALITY, *LPD3DRMRENDERQUALITY;

typedef enum _D3DRMTEXTUREQUALITY {
    D3DRMTEXTURE_NEAREST,
    D3DRMTEXTURE_LINEAR,
    D3DRMTEXTURE_MIPNEAREST,
    D3DRMTEXTURE_MIPLINEAR,
    D3DRMTEXTURE_LINEARMIPNEAREST,
    D3DRMTEXTURE_LINEARMIPLINEAR
} D3DRMTEXTUREQUALITY, *LPD3DRMTEXTUREQUALITY;

typedef enum _D3DRMCOMBINETYPE {
    D3DRMCOMBINE_REPLACE,
    D3DRMCOMBINE_BEFORE,
    D3DRMCOMBINE_AFTER
} D3DRMCOMBINETYPE, *LPD3DRMCOMBINETYPE;

typedef struct _D3DRMPALETTEENTRY {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char flags;
} D3DRMPALETTEENTRY, *LPD3DRMPALETTEENTRY;

typedef struct _D3DRMIMAGE {
    int width;
    int height;
    int aspectx;
    int aspecty;
    int depth;
    int rgb;
    int bytes_per_line;
    void* buffer1;
    void* buffer2;
    unsigned long red_mask;
    unsigned long green_mask;
    unsigned long blue_mask;
    unsigned long alpha_mask;
    int palette_size;
    D3DRMPALETTEENTRY* palette;
} D3DRMIMAGE, *LPD3DRMIMAGE;

typedef enum _D3DRMWRAPTYPE {
    D3DRMWRAP_FLAT,
    D3DRMWRAP_CYLINDER,
    D3DRMWRAP_SPHERE,
    D3DRMWRAP_CHROME,
    D3DRMWRAP_SHEET,
    D3DRMWRAP_BOX
} D3DRMWRAPTYPE, *LPD3DRMWRAPTYPE;

typedef enum _D3DRMPROJECTIONTYPE
{
    D3DRMPROJECT_PERSPECTIVE,
    D3DRMPROJECT_ORTHOGRAPHIC,
    D3DRMPROJECT_RIGHTHANDPERSPECTIVE,
    D3DRMPROJECT_RIGHTHANDORTHOGRAPHIC
} D3DRMPROJECTIONTYPE, *LPD3DRMPROJECTIONTYPE;

typedef enum _D3DRMXOFFORMAT {
    D3DRMXOF_BINARY,
    D3DRMXOF_COMPRESSED,
    D3DRMXOF_TEXT
} D3DRMXOFFORMAT, *LPD3DRMXOFFORMAT;

typedef DWORD D3DRMSAVEOPTIONS;

typedef enum _D3DRMCOLORSOURCE {
    D3DRMCOLOR_FROMFACE,
    D3DRMCOLOR_FROMVERTEX
} D3DRMCOLORSOURCE, *LPD3DRMCOLORSOURCE;

typedef enum _D3DRMFRAMECONSTRAINT {
    D3DRMCONSTRAIN_Z,
    D3DRMCONSTRAIN_Y,
    D3DRMCONSTRAIN_X
} D3DRMFRAMECONSTRAINT, *LPD3DRMFRAMECONSTRAINT;

typedef enum _D3DRMMATERIALMODE {
    D3DRMMATERIAL_FROMMESH,
    D3DRMMATERIAL_FROMPARENT,
    D3DRMMATERIAL_FROMFRAME
} D3DRMMATERIALMODE, *LPD3DRMMATERIALMODE;

typedef enum _D3DRMFOGMODE {
    D3DRMFOG_LINEAR,
    D3DRMFOG_EXPONENTIAL,
    D3DRMFOG_EXPONENTIALSQUARED
} D3DRMFOGMODE, *LPD3DRMFOGMODE;

typedef enum _D3DRMZBUFFERMODE {
    D3DRMZBUFFER_FROMPARENT,
    D3DRMZBUFFER_ENABLE,
    D3DRMZBUFFER_DISABLE
} D3DRMZBUFFERMODE, *LPD3DRMZBUFFERMODE;

typedef enum _D3DRMSORTMODE {
    D3DRMSORT_FROMPARENT,
    D3DRMSORT_NONE,
    D3DRMSORT_FRONTTOBACK,
    D3DRMSORT_BACKTOFRONT
} D3DRMSORTMODE, *LPD3DRMSORTMODE;

typedef struct _D3DRMMATERIALOVERRIDE {
    DWORD         dwSize;
    DWORD         dwFlags;
    D3DCOLORVALUE dcDiffuse;
    D3DCOLORVALUE dcAmbient;
    D3DCOLORVALUE dcEmissive;
    D3DCOLORVALUE dcSpecular;
    D3DVALUE      dvPower;
    LPUNKNOWN     lpD3DRMTex;
} D3DRMMATERIALOVERRIDE, *LPD3DRMMATERIALOVERRIDE;

typedef DWORD D3DRMLOADOPTIONS;

#define D3DRMLOAD_FROMFILE             0x000L
#define D3DRMLOAD_FROMRESOURCE         0x001L
#define D3DRMLOAD_FROMMEMORY           0x002L
#define D3DRMLOAD_FROMSTREAM           0x004L
#define D3DRMLOAD_FROMURL              0x008L

#define D3DRMLOAD_BYNAME               0x010L
#define D3DRMLOAD_BYPOSITION           0x020L
#define D3DRMLOAD_BYGUID               0x040L
#define D3DRMLOAD_FIRST                0x080L

#define D3DRMLOAD_INSTANCEBYREFERENCE  0x100L
#define D3DRMLOAD_INSTANCEBYCOPYING    0x200L

#define D3DRMLOAD_ASYNCHRONOUS         0x400L

typedef struct _D3DRMLOADRESOURCE {
    HMODULE hModule;
    LPCSTR /*LPCTSTR*/ lpName;
    LPCSTR /*LPCTSTR*/ lpType;
} D3DRMLOADRESOURCE, *LPD3DRMLOADRESOURCE;

typedef struct _D3DRMLOADMEMORY {
    LPVOID lpMemory;
    DWORD dSize;
} D3DRMLOADMEMORY, *LPD3DRMLOADMEMORY;

typedef struct _D3DRMPMESHLOADSTATUS {
    DWORD dwSize;
    DWORD dwPMeshSize;
    DWORD dwBaseMeshSize;
    DWORD dwBytesLoaded;
    DWORD dwVerticesLoaded;
    DWORD dwFacesLoaded;
    HRESULT dwLoadResult;
    DWORD dwFlags;
} D3DRMPMESHLOADSTATUS, *LPD3DRMPMESHLOADSTATUS;

typedef enum _D3DRMUSERVISUALREASON {
    D3DRMUSERVISUAL_CANSEE,
    D3DRMUSERVISUAL_RENDER
} D3DRMUSERVISUALREASON, *LPD3DRMUSERVISUALREASON;

typedef DWORD D3DRMMAPPING;

typedef struct _D3DRMVERTEX {
    D3DVECTOR position;
    D3DVECTOR normal;
    D3DVALUE  tu;
    D3DVALUE  tv;
    D3DCOLOR  color;
} D3DRMVERTEX, *LPD3DRMVERTEX;

typedef LONG D3DRMGROUPINDEX;

void WINAPI D3DRMMatrixFromQuaternion(D3DRMMATRIX4D, LPD3DRMQUATERNION);

LPD3DRMQUATERNION WINAPI D3DRMQuaternionFromRotation(LPD3DRMQUATERNION ,LPD3DVECTOR,D3DVALUE);
LPD3DRMQUATERNION WINAPI D3DRMQuaternionMultiply(LPD3DRMQUATERNION, LPD3DRMQUATERNION, LPD3DRMQUATERNION);
LPD3DRMQUATERNION WINAPI D3DRMQuaternionSlerp(LPD3DRMQUATERNION, LPD3DRMQUATERNION, LPD3DRMQUATERNION, D3DVALUE);

LPD3DVECTOR WINAPI D3DRMVectorAdd(LPD3DVECTOR, LPD3DVECTOR, LPD3DVECTOR);
LPD3DVECTOR WINAPI D3DRMVectorCrossProduct(LPD3DVECTOR, LPD3DVECTOR, LPD3DVECTOR);
D3DVALUE WINAPI D3DRMVectorDotProduct(LPD3DVECTOR, LPD3DVECTOR);
LPD3DVECTOR WINAPI D3DRMVectorNormalize(LPD3DVECTOR);

#define D3DRMVectorNormalise D3DRMVectorNormalize

D3DVALUE WINAPI D3DRMVectorModulus(LPD3DVECTOR);
LPD3DVECTOR WINAPI D3DRMVectorRandom(LPD3DVECTOR);
LPD3DVECTOR WINAPI D3DRMVectorRotate(LPD3DVECTOR, LPD3DVECTOR, LPD3DVECTOR, D3DVALUE);
LPD3DVECTOR WINAPI D3DRMVectorReflect(LPD3DVECTOR, LPD3DVECTOR, LPD3DVECTOR);
LPD3DVECTOR WINAPI D3DRMVectorScale(LPD3DVECTOR, LPD3DVECTOR, D3DVALUE);
LPD3DVECTOR WINAPI D3DRMVectorSubtract(LPD3DVECTOR, LPD3DVECTOR, LPD3DVECTOR);

D3DCOLOR WINAPI D3DRMCreateColorRGB(D3DVALUE, D3DVALUE, D3DVALUE);
D3DCOLOR WINAPI D3DRMCreateColorRGBA(D3DVALUE, D3DVALUE, D3DVALUE, D3DVALUE);
D3DVALUE WINAPI D3DRMColorGetAlpha(D3DCOLOR);
D3DVALUE WINAPI D3DRMColorGetBlue(D3DCOLOR);
D3DVALUE WINAPI D3DRMColorGetGreen(D3DCOLOR);
D3DVALUE WINAPI D3DRMColorGetRed(D3DCOLOR);

#if defined(__cplusplus)
}
#endif

#endif
