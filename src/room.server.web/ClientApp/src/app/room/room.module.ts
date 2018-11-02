import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { RoomLoginComponent } from './login/room.login.component';
import { RoomDashboardComponent } from './dashboard/room.dashboard.component';

import { RoomRoutingModule } from './room-routing.module';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    RoomRoutingModule
  ],
  declarations: [
    RoomLoginComponent,
    RoomDashboardComponent
  ]
})
export class RoomModule {

  
}
