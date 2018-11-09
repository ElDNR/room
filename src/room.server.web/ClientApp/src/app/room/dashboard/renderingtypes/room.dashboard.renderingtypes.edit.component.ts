import { Component, Inject } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Router } from '@angular/router';

import { RoomDashboardAuthenticatorComponent } from '../room.dashboard.authenticator.component';

@Component({
  selector: 'app-roomdashboardrenderingtypesedit',
  templateUrl: './room.dashboard.renderingtypes.edit.component.html'
})
export class RoomDashboardRenderingTypesEditComponent extends RoomDashboardAuthenticatorComponent {

  public RenderingType = { Name: "", Handler: "" }

  constructor(router: Router, http: HttpClient, @Inject('BASE_URL') baseUrl: string) {
    super(router, http, baseUrl);
  }

  protected onInit(): void {
    console.log("RoomDashboardRenderingsTypesEditComponent authenticated.");
  }

  public submitEdit() {
    alert(this.RenderingType.Name + " | " + this.RenderingType.Handler);
  }

}
