import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';

import { RoomLoginComponent } from './login/room.login.component';
import { RoomDashboardComponent } from './dashboard/room.dashboard.component';
import { RoomDashboardRenderingsComponent } from './dashboard/renderings/room.dashboard.renderings.component';
import { RoomDashboardRenderingsEditComponent } from './dashboard/renderings/room.dashboard.renderings.edit.component';
import { RoomDashboardRenderingTypesComponent } from './dashboard/renderingtypes/room.dashboard.renderingtypes.component';
import { RoomDashboardRenderingTypesEditComponent } from './dashboard/renderingtypes/room.dashboard.renderingtypes.edit.component';
import { RoomDashboardScenesComponent } from './dashboard/scenes/room.dashboard.scenes.component';
import { RoomDashboardScenesEditComponent } from './dashboard/scenes/room.dashboard.scenes.edit.component';

const roomRoutes: Routes = [
  { path: 'room', component: RoomLoginComponent },
  { path: 'room/dashboard', component: RoomDashboardComponent },
  { path: 'room/dashboard/renderings', component: RoomDashboardRenderingsComponent },
  { path: 'room/dashboard/renderings/edit/:id', component: RoomDashboardRenderingsEditComponent },
  { path: 'room/dashboard/renderingtypes', component: RoomDashboardRenderingTypesComponent },
  { path: 'room/dashboard/renderingtypes/edit/:id', component: RoomDashboardRenderingTypesEditComponent },
  { path: 'room/dashboard/scenes', component: RoomDashboardScenesComponent },
  { path: 'room/dashboard/scenes/edit/:id', component: RoomDashboardScenesEditComponent }
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
