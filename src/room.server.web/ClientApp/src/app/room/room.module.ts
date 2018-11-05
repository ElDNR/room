import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { RoomLoginComponent } from './login/room.login.component';
import { RoomDashboardComponent } from './dashboard/room.dashboard.component';
import { RoomDashboardRenderingsComponent } from './dashboard/renderings/room.dashboard.renderings.component';
import { RoomDashboardRenderingsEditComponent } from './dashboard/renderings/room.dashboard.renderings.edit.component';
import { RoomDashboardRenderingTypesComponent } from './dashboard/renderingtypes/room.dashboard.renderingtypes.component';
import { RoomDashboardRenderingTypesEditComponent } from './dashboard/renderingtypes/room.dashboard.renderingtypes.edit.component';
import { RoomDashboardScenesComponent } from './dashboard/scenes/room.dashboard.scenes.component';
import { RoomDashboardScenesEditComponent } from './dashboard/scenes/room.dashboard.scenes.edit.component';

import { RoomRoutingModule } from './room-routing.module';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    RoomRoutingModule
  ],
  declarations: [
    RoomLoginComponent,
    RoomDashboardComponent,
    RoomDashboardRenderingsComponent,
    RoomDashboardRenderingsEditComponent,
    RoomDashboardRenderingTypesComponent,
    RoomDashboardRenderingTypesEditComponent,
    RoomDashboardScenesComponent,
    RoomDashboardScenesEditComponent
  ]
})
export class RoomModule {
}
