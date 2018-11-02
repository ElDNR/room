import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';

import { RoomLoginComponent } from './login/room.login.component';
import { RoomDashboardComponent } from './dashboard/room.dashboard.component';

const roomRoutes: Routes = [
  { path: 'room', component: RoomLoginComponent },
  { path: 'room/dashboard', component: RoomDashboardComponent }
];

@NgModule({
  imports: [
    RouterModule.forChild(roomRoutes)
  ],
  exports: [
    RouterModule
  ]
})
export class RoomRoutingModule { }
