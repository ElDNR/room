import { Component, Inject } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Router } from '@angular/router';

import { RoomDashboardAuthenticatorComponent } from '../room.dashboard.authenticator.component';

@Component({
  selector: 'app-roomdashboardscenes',
  templateUrl: './room.dashboard.scenes.component.html'
})
export class RoomDashboardScenesComponent extends RoomDashboardAuthenticatorComponent {

  constructor(router: Router, http: HttpClient, @Inject('BASE_URL') baseUrl: string) {
    super(router, http, baseUrl);
  }

  public onInit() {
    console.log("RoomDashboardScenesComponent authenticated.");
  }

}
