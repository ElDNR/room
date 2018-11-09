import { Component, Inject, OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Router } from '@angular/router';
import { RoomDashboardAuthenticator } from '../room.dashboard.authenticator';

import { RoomDashboardAuthenticatorComponent } from '../room.dashboard.authenticator.component';

@Component({
  selector: 'app-roomdashboardrenderingtypes',
  templateUrl: './room.dashboard.renderingtypes.component.html'
})
export class RoomDashboardRenderingTypesComponent extends RoomDashboardAuthenticatorComponent {

  public RenderingTypes = [];
  public ShowNoRenderingTypesMessage: boolean = false;

  constructor(router: Router, http: HttpClient, @Inject('BASE_URL') baseUrl: string) {
    super(router, http, baseUrl);
  }

  protected onInit(): void {
    console.log("RoomDashboardRenderingsTypesComponent authenticated.");

    this.ShowNoRenderingTypesMessage = true;
  }

}
