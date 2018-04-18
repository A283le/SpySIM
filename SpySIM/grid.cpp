#include "grid.h"

void Grid::DrawIsoRow(wxRealPoint& point, int difficulty)
{
    wxRealPoint *center = new wxRealPoint(point);
    DrawIsoSquare(*center);

    num_tiles = 0;
    if(difficulty == 0)
        num_tiles = 15;
    else if(difficulty == 1)
        num_tiles = 10;
    else if(difficulty == 2)
        num_tiles = 5;

    wxRealPoint **array = new wxRealPoint*[num_tiles];

    for(int i = 0; i < num_tiles-1; i++){ // define a max number or rows
        array[i] = new wxRealPoint(*center);    // based on the panel width
        array[i]->x += tile_size * (i+1);

        DrawIsoSquare(*array[i]);
    }

    if(center != NULL){
        delete center;
        center = NULL;
    }
    if(array != NULL){
        delete [] array;
        array = NULL;
    }
}

void Grid::DrawIsoGrid(wxRealPoint& point, wxRadioBox* RadioBox){

    wxClientDC dc(Panel1);
    //dc.Clear();
    wxRealPoint *center = new wxRealPoint(point);
    DrawIsoRow(*center, RadioBox1->GetSelection());

    wxRealPoint **array = new wxRealPoint*[5];

    for(int i = 0; i < 4; i++){ // define a max number or rows
        array[i] = new wxRealPoint(*center);    // based on the panel width
        array[i]->x += (tile_size * cos(PI/6)) * (i + 1);
        array[i]->y -= (tile_size * 0.5) * (i + 1);

        DrawIsoRow(*array[i], RadioBox->GetSelection());
    }
}